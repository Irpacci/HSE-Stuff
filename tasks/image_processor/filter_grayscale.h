#ifndef FILTER_GRAYSCALE_H
#define FILTER_GRAYSCALE_H

#include "base_filter.h"
#include "image.h"

class GrayscaleFilter : public BaseFilter {
public:
    explicit GrayscaleFilter(FilterSetting a) {
    }
    GrayscaleFilter() {
    }
    ~GrayscaleFilter() override {
    }
    void Apply(BMPImage &image) override;
};

#endif