#ifndef FILTER_GRAYSCALE_H
#define FILTER_GRAYSCALE_H

#include "base_filter.h"
#include "image.h"

class GrayscaleFilter : public BaseFilter {
public:
    GrayscaleFilter(FilterSetting a) {
    }
    GrayscaleFilter() {
    }
    ~GrayscaleFilter() {
    }
    void Apply(BMPImage &image) override;
};

#endif