#ifndef FILTER_BLUR_H
#define FILTER_BLUR_H

#include <string>

#include "base_filter.h"
#include "image.h"

class BlurFilter : public BaseFilter {
public:
    explicit BlurFilter(const FilterSetting& a) : sigma_{stold(a.parameters[0])} {
    }
    void Apply(BMPImage& image) override;
    BaseFilter* CreateBlurFilter(const FilterSetting& setting) {
        return new BlurFilter(setting);
    }

private:
    long double sigma_;
};

#endif