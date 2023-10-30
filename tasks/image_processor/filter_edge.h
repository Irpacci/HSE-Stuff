#ifndef FILTER_EDGE_H
#define FILTER_EDGE_H

#include <string>

#include "base_filter.h"
#include "image.h"

const double MAX_INT8 = 255.0;

class EdgeFilter : public BaseFilter {
public:
    explicit EdgeFilter(FilterSetting a) : threshold_{stold(a.parameters[0]) * MAX_INT8} {
    }
    void Apply(BMPImage &image) override;

private:
    long double threshold_;
};

#endif