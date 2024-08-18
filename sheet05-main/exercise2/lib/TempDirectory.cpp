#include "lib/TempDirectory.hpp"
#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>
#include <unistd.h>

namespace raii {

// Constructor for creating a temporary directory at the specified path.
TempDirectory::TempDirectory(const std::string& path)
    : path(path) {
    osapi::createDir(path.c_str());
    dirFd = osapi::openDir(path.c_str());
    if (dirFd < 0) {
        throw std::runtime_error("Failed to open directory: " + path);
    }
}

// Constructor for creating a temporary subdirectory within a parent directory.
TempDirectory::TempDirectory(int parentFd, const std::string& name)
    : path(name) {
    osapi::createSubdir(parentFd, name.c_str());
    dirFd = osapi::openSubdir(parentFd, name.c_str());
    if (dirFd < 0) {
        throw std::runtime_error("Failed to open subdirectory: " + path);
    }
}

// Destructor for cleaning up resources associated with the temporary directory.
TempDirectory::~TempDirectory() {
    cleanUp();
    close(dirFd);
}

// Get the file descriptor of the temporary directory.
int TempDirectory::getFd() const {
    return dirFd;
}

// Get the path of the temporary directory.
const std::string& TempDirectory::getPath() const {
    return path;
}

// Recursively clean up subdirectories and delete files within the directory.
void TempDirectory::cleanUp() {
    // First, recursively clean subdirectories
    for (auto& subdir : subdirectories) {
        subdir->cleanUp();
        subdir.reset();
    }
    subdirectories.clear();

    // Then, delete any files in the directory
    // Implement file deletion logic here, possibly using <filesystem> operations

    // Finally, remove the directory itself
    osapi::removeDir(path.c_str());
}

} // namespace raii