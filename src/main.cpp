#include <iostream>

#include <filesystem>
#include <vector>
#include <string>

#include "DirectoryHandler.h"

std::vector<std::string> argsToString(int argc, char** argv) {
    std::vector<std::string> args;
    for(int i = 0; i < argc; i++) {
        args.push_back(std::string(argv[i]));
    }
    return args;
}

void argsMenu() {
    std::cout << "Enter arguments:" << std::endl;
    std::cout << "1. Path to send items to (-a for auto pathing)" << std::endl;
    std::cout << "2.  Main folder to contain other directories" << std::endl;
    std::cout << "3+. Sub folder names" << std::endl;
    std::cout << "-l {folder} : adds a labs folder to class" << std::endl;
    std::cout << "Ex: ./Semester-Creator ./ \"Main Folder\" Subfolder -l \"Subfolder with lab\" -l \"Another lab\" \"No Lab\"" << std::endl;
}

int main(int argc, char** argv) {
    if (argc <= 3) {
        argsMenu();
        return 0;
    }

    auto args = argsToString(argc, argv);

    DirectoryHandler dh(args[1], args[2]);
    auto failed = dh.mkdirs(args);
    for(const std::string& file : failed) {
        std::cout << "Could not create " << file << std::endl;
    }

    dh.showTree();

    return 0;
}

