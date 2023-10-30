#ifndef FILTER_EDGE_H
#define FILTER_EDGE_H

#include <string>

#include "base_filter.h"
#include "image.h"

class EdgeFilter : public BaseFilter {
public:
    EdgeFilter(FilterSetting a) : threshold_{stold(a.parameters[0]) * 255.0} {
    }
    EdgeFilter() {
    }
    ~EdgeFilter() {
    }
    void Apply(BMPImage &image) override;

private:
    long double threshold_;
};

#endif