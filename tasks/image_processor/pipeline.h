#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>

#include "base_filter.h"
#include "image.h"

class Pipeline {
public:
    void AddFilter(BaseFilter* iterator);
    void Apply(BMPImage& image);

private:
    std::vector<BaseFilter*> filters_;
};

#endif