#ifndef FILTER_NEGATIVE_H
#define FILTER_NEGATIVE_H

#include "base_filter.h"
#include "image.h"

class NegativeFilter : public BaseFilter {
public:
    explicit NegativeFilter(FilterSetting a) {
    }
    void Apply(BMPImage &image) override;
};

#endif