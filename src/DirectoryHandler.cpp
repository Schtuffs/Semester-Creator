#include "DirectoryHandler.h"

DirectoryHandler::DirectoryHandler(const std::string& path, const std::string& mainfolder) {
    // For autopathing
    if (path == "-a") {
        this->setDir(AUTO_PATH);
    }
    // Manually entered path
    else {
        this->setDir(path);
    }
    
    // Makes the main folder then moves directory into it
    if (!this->mkdir(mainfolder)) {
        // Prints message to user saying main folder could not be created in the path
        // Prevents filling already created folder
        std::cout << "Could not create: " << (path == "-a" ? "autopath" : path) << '/' << mainfolder << std::endl;
        exit(EXIT_FAILURE);
    }
    this->setDir("./" + mainfolder);
}

bool DirectoryHandler::mkdir(const std::string& foldername, const std::string& subfolder) {
    if (subfolder.length() > 0)
        return std::filesystem::create_directories(foldername + "/" + subfolder);
    return std::filesystem::create_directory(foldername);
}

void DirectoryHandler::setDir(const std::string& path) {
    try {
        std::filesystem::current_path(path);
    }
    // Prevent failed filepath changes from creating files in undesireable locations
    catch (std::filesystem::filesystem_error e) {
        std::cout << path << " is not a valid path..." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void DirectoryHandler::parse(const std::string& tag) {
    // Only 1 tag to parse at the moment
    if (tag == "-l") {
        this->createLab = true;
    }
}

std::vector<std::string> DirectoryHandler::mkdirs(const std::vector<std::string>& folders) {
    std::vector<std::string> failedFolders;
    // Removes arguments for .exe filepath, directory, or main folder
    for (int i = 3; i < folders.size(); i++) {
        // Parse tag
        if (folders[i][0] == '-') {
            this->parse(folders[i]);
            continue;
        }

        // Check if lab should be created
        if (this->createLab) {
            if (!this->mkdir(folders[i], "labs")) {
                failedFolders.push_back(folders[i] + "/" + "labs");
            }
        }

        // Always creates assignments and notes
        if (!this->mkdir(folders[i], "assignments")) {
            failedFolders.push_back(folders[i] + "/" + "assignments");
        }
        if (!this->mkdir(folders[i], "notes")) {
            failedFolders.push_back(folders[i] + "/" + "notes");
        }

        // Reset tags after folder is created
        this->reset();
    }
    return failedFolders;
}

void DirectoryHandler::reset() {
    this->createLab = false;
}

void DirectoryHandler::showTree() {
    std::system("tree ./");
}

DirectoryHandler::~DirectoryHandler() {
    // Nothing todo
}

