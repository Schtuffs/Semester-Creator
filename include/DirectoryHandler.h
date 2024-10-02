#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

// Change this if you would like your autopath to be somewhere else
#define AUTO_PATH   "../"

class DirectoryHandler {
private:
    bool createLab;

    bool mkdir(const std::string& foldername, const std::string& subfolder = "");
    void setDir(const std::string& path);
    void parse(const std::string& tag);
    void reset();

public:
    DirectoryHandler(const std::string& path, const std::string& mainfolder);

    std::vector<std::string> mkdirs(const std::vector<std::string>& folders);

    void showTree();
    
    ~DirectoryHandler();
};

