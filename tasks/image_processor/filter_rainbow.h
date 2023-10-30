#ifndef FILTER_RAINBOW_H
#define FILTER_RAINBOW_H

#include "base_filter.h"
#include "image.h"

#include <string>

class RainbowFilter : public BaseFilter {
public:
    explicit RainbowFilter(FilterSetting a) : rainbow_width_{std::stoi(a.parameters[0])} {
    }
    RainbowFilter() {
    }
    ~RainbowFilter() override {
    }
    void Apply(BMPImage &image) override;

private:
    int32_t rainbow_width_;
};

#endif