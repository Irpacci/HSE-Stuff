#ifndef FILTER_CROP_H
#define FILTER_CROP_H

#include <string>

#include "base_filter.h"
#include "image.h"

class CropFilter : public BaseFilter {
public:
    CropFilter(FilterSetting a) : new_height_{stoi(a.parameters[1])}, new_width_{stoi(a.parameters[0])} {
    }
    CropFilter() {
    }
    ~CropFilter() {
    }
    void Apply(BMPImage &image) override;

private:
    int32_t new_height_;
    int32_t new_width_;
};

#endif