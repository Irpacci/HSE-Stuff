#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <cstdint>

#include "filter_setting.h"

class Parser {
public:
    const std::string FILENAME_PREFIX = "../tasks/image_processor/";

public:
    void Parse(char* commands[], int32_t size);
    std::string& GetFilename();
    std::string& GetOutput();
    std::vector<FilterSetting>& GetParsed() {
        return filter_commands_;
    }

private:
    std::string filename_;
    std::string output_;
    std::vector<FilterSetting> filter_commands_;
};

#endif