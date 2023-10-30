#ifndef FILTER_PRODUCTION_H
#define FILTER_PRODUCTION_H

#include <map>
#include <string>
#include <vector>
#include "base_filter.h"
#include "filter_blur.h"
#include "filter_crop.h"
#include "filter_edge.h"
#include "filter_grayscale.h"
#include "filter_negative.h"
#include "filter_sharp.h"
#include "filter_rainbow.h"

using FilterProdPtr = BaseFilter* (*)(FilterSetting);

BaseFilter* CreateBlurFilter(FilterSetting setting) {
    return new BlurFilter(setting);
}

BaseFilter* CreateCropFilter(FilterSetting setting) {
    return new CropFilter(setting);
}

BaseFilter* CreateEdgeFilter(FilterSetting setting) {
    return new EdgeFilter(setting);
}

BaseFilter* CreateGrayscaleFilter(FilterSetting setting) {
    return new GrayscaleFilter(setting);
}

BaseFilter* CreateNegativeFilter(FilterSetting setting) {
    return new NegativeFilter(setting);
}

BaseFilter* CreateSharpFilter(FilterSetting setting) {
    return new SharpFilter(setting);
}

BaseFilter* CreateRainbowFilter(FilterSetting setting) {
    return new RainbowFilter(setting);
}

class FilterFactory {
public:
    std::map<std::string, FilterProdPtr> filters = {{"crop", CreateCropFilter},    {"blur", CreateBlurFilter},
                                                    {"gs", CreateGrayscaleFilter}, {"neg", CreateNegativeFilter},
                                                    {"sharp", CreateSharpFilter},  {"edge", CreateEdgeFilter},
                                                    {"bow", CreateRainbowFilter}};
    BaseFilter* Generate(FilterSetting setting) {
        FilterProdPtr generator = filters[setting.filtername];
        return generator(setting);
    }
};

#endif