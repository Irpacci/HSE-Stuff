#ifndef FILTER_SETTING_H
#define FILTER_SETTING_H

#include <map>
#include <string>
#include <vector>

class FilterSetting {
public:
    FilterSetting(){};
    ~FilterSetting(){};

public:
    std::string filtername;
    std::vector<std::string> parameters;
};

#endif  // FILTER_SETTING_H