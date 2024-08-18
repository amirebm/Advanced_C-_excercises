#ifndef H_lib_TempDirectory
#define H_lib_TempDirectory

#include "lib/OSApi.hpp"
#include <memory>
#include <string>
#include <vector>

namespace raii {

// Class representing a temporary directory with RAII-based resource management.
class TempDirectory {
    public:
    // Constructor for creating a temporary directory at the specified path.
    TempDirectory(const std::string& path);

    // Constructor for creating a temporary subdirectory within a parent directory.
    TempDirectory(int parentFd, const std::string& name);

    // Destructor for cleaning up resources associated with the temporary directory.
    ~TempDirectory();

    // Delete copy and move operations to ensure proper resource management.
    TempDirectory(const TempDirectory&) = delete;
    TempDirectory& operator=(const TempDirectory&) = delete;
    TempDirectory(TempDirectory&&) = delete;
    TempDirectory& operator=(TempDirectory&&) = delete;

    // Get the file descriptor of the temporary directory.
    int getFd() const;

    // Get the path of the temporary directory.
    const std::string& getPath() const;

    private:
    std::string path;
    int dirFd;
    std::vector<std::shared_ptr<TempDirectory>> subdirectories;

    // Recursively clean up subdirectories and delete files within the directory.
    void cleanUp();
};

} // namespace raii

#endif