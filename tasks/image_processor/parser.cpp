#include "parser.h"

#include <iostream>

void Parser::Parse(char* commands[], int32_t size) {
    filename_ = commands[1];
    output_ = commands[2];
    FilterSetting current;
    for (int32_t i = 3; i < size; i++) {
        std::string current_command = commands[i];
        if (current_command[0] == '-') {
            if (!current.filtername.empty()) {
                filter_commands_.push_back(current);
            }
            current = FilterSetting();
            current.filtername = current_command.substr(1);
        } else {
            current.parameters.push_back(current_command);
        }
    }
    if (!current.filtername.empty()) {
        filter_commands_.push_back(current);
    }
    for (auto const& x : filter_commands_) {
        std::cout << "name:" << ' ' << x.filtername << std::endl << "parameters: ";
        for (auto const& h : x.parameters) {
            std::cout << h << ' ';
        }
        std::cout << std::endl;
    }
}

std::string& Parser::GetFilename() {
    return filename_;
}

std::string& Parser::GetOutput() {
    return output_;
}