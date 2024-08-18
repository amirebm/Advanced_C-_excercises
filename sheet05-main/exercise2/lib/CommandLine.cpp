#include "lib/CommandLine.hpp"
#include <filesystem>
#include <iostream>
#include <sstream>

namespace raii {

// Function to run the command line interface with a specified base directory.
void CommandLine::run(const std::string& basedir) {
    currentDir = std::make_shared<TempDirectory>(basedir);
    std::string command;

    // Main loop for handling user input commands.
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        handleCommand(command);
        if (command == "quit") {
            break;
        }
    }
}

// Function to handle various commands entered by the user.
void CommandLine::handleCommand(const std::string& command) {
    if (command == "enter") {
        // Create a new temporary directory and enter into it.
        auto newDir = std::make_shared<TempDirectory>(currentDir->getFd(), "dir" + std::to_string(dirCount++));
        currentDir = newDir;
        std::cout << "entering directory " << currentDir->getPath() << std::endl;
    } else if (command == "current") {
        // Display the current working directory.
        std::cout << "current directory: " << currentDir->getPath() << std::endl;
    } else if (command == "leave") {
        // Leave the current directory.
        if (currentDir) {
            std::cout << "leaving directory " << currentDir->getPath() << std::endl;
            currentDir = nullptr;
        }
    } else if (command == "create") {
        // Create a new temporary file in the current directory.
        auto newFile = std::make_shared<TempFile>(*currentDir, "file" + std::to_string(fileCount++));
        tempFiles.push_back(newFile);
        std::cout << "created file " << newFile->getPath() << std::endl;
    } else if (command == "list") {
        // List all created temporary files.
        for (size_t i = 0; i < tempFiles.size(); ++i) {
            std::cout << "[" << i << "] " << tempFiles[i]->getPath() << std::endl;
        }
    } else if (command.rfind("remove", 0) == 0) {
        // Remove a specific temporary file based on user input.
        std::istringstream iss(command);
        std::string cmd;
        std::size_t fileIndex;
        iss >> cmd >> fileIndex;
        if (fileIndex < tempFiles.size()) {
            std::cout << "removed file " << tempFiles[fileIndex]->getPath() << std::endl;
            tempFiles.erase(tempFiles.begin() + fileIndex);
        }
    } else if (command == "quit") {
        // Quit the command line interface, clearing all temporary files and directories.
        tempFiles.clear();
        currentDir = nullptr;
        std::cout << "quitting" << std::endl;
    } else {
        // Display a message for unknown comands.
        std::cout << "wrong command" << std::endl;
    }
}

} // namespace raii