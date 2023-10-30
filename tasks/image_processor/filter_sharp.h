#ifndef FILTER_SHARP_H
#define FILTER_SHARP_H

#include "base_filter.h"
#include "image.h"

class SharpFilter : public BaseFilter {
public:
    explicit SharpFilter(FilterSetting a) {
    }
    SharpFilter() {
    }
    ~SharpFilter() override {
    }
    void Apply(BMPImage &image) override;
};

#endif