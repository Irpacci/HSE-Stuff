#include <vector>

#include "unixpath.h"

void CheckString(std::string& folder, std::vector<std::string>& folders) {
    if (folder == ".." && !folders.empty()) {
        folders.pop_back();
    }
    if (folder == "" || folder == "." || folder == "..") {
        return;
    }
    folders.push_back(folder);
}

std::string NormalizePath(std::string_view current_working_dir, std::string_view path) {
    std::vector<std::string> folders;
    for (char character : current_working_dir) {
        if (character == '/') {
            folders.push_back("");
        } else {
            folders.back() += character;
        }
    }
    std::string current_folder = "";
    for (char character : path) {
        if (character == '/') {
            CheckString(current_folder, folders);
            current_folder = "";
        } else {
            current_folder += character;
        }
    }
    CheckString(current_folder, folders);
    std::string answer = "";
    for (std::string folder : folders) {
        answer += "/" + folder;
    }
    if (answer.empty()) {
        answer = "/";
    }
    return answer;
}
