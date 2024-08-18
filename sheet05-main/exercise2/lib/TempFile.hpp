#ifndef H_lib_TempFile
#define H_lib_TempFile

#include "TempDirectory.hpp"
#include "lib/OSApi.hpp"
#include <memory>
#include <string>

namespace raii {

class TempDirectory;

// Class representing a temporary file with RAII-based resource management.
class TempFile {
    public:
    // Constructor for creating a temporary file within a specified parent directory.
    TempFile(TempDirectory& parentDir, const std::string& name);

    // Destructor for releasing resources associated with the temporary file.
    ~TempFile();

    // Move constructor for efficient resource transfer.
    TempFile(TempFile&& other) noexcept;

    // Move assignment operator for efficient resource transfer.
    TempFile& operator=(TempFile&& other) noexcept;

    // Get the path of the temporary file.
    const std::string& getPath() const;

    private:
    std::string path;
    int fileFd;

    // Release resources associated with the temporary file.
    void releaseResources();
};

} // namespace raii

#endif