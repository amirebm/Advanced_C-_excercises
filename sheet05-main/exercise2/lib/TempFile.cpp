#include "lib/TempFile.hpp"
#include <iostream>
#include <string>

namespace raii {

// Constructor for creating a temporary file within a specified parent directory.
TempFile::TempFile(TempDirectory& parentDir, const std::string& name)
    : path(parentDir.getPath() + "/" + name),
      fileFd(osapi::openFile(parentDir.getFd(), name.c_str())) {
    if (fileFd < 0) {
        throw std::runtime_error("Failed to create file: " + path);
    }
}

// Destructor for releasing resources associated with the temporary file.
TempFile::~TempFile() {
    releaseResources();
}

// Move constructor for efficient resource transfer.
TempFile::TempFile(TempFile&& other) noexcept
    : path(std::move(other.path)), fileFd(other.fileFd) {
    other.fileFd = -1;
}

// Move assignment operator for efficient resource transfer.
TempFile& TempFile::operator=(TempFile&& other) noexcept {
    if (this != &other) {
        releaseResources();
        path = std::move(other.path);
        fileFd = other.fileFd;
        other.fileFd = -1;
    }
    return *this;
}

// Get the path of the temporary file.
const std::string& TempFile::getPath() const {
    return path;
}

// Release resources associated with the temporary file.
void TempFile::releaseResources() {
    if (fileFd >= 0) {
        osapi::removeFile(fileFd, path.c_str());
        close(fileFd);
        fileFd = -1;
    }
}

} // namespace raii