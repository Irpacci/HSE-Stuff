#include "pipeline.h"

void Pipeline::AddFilter(BaseFilter* iterator) {
    filters.push_back(iterator);
}

void Pipeline::Apply(BMPImage& image) {
    for (BaseFilter* x : filters) {
        x->Apply(image);
    }
}