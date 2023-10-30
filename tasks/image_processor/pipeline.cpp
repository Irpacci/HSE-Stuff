#include "pipeline.h"

void Pipeline::AddFilter(BaseFilter* iterator) {
    filters_.push_back(iterator);
}

void Pipeline::Apply(BMPImage& image) {
    for (BaseFilter* x : filters_) {
        x->Apply(image);
    }
}