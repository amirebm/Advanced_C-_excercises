#ifndef H_lib_CommandLine
#define H_lib_CommandLine

#include "lib/TempDirectory.hpp"
#include "lib/TempFile.hpp"
#include <memory>
#include <string>
#include <vector>

namespace raii {

// Class representing a command line interface with RAII-based temporary file and directory management.
class CommandLine {
    public:
    // Run the command line interface with a specified base directory.
    void run(const std::string& basedir);

    private:
    std::shared_ptr<TempDirectory> currentDir;
    std::vector<std::shared_ptr<TempFile>> tempFiles;
    int dirCount = 0;
    int fileCount = 0;

    // Function to handle various commands entered by the user.
    void handleCommand(const std::string& command);

};

} // namespace raii

#endif