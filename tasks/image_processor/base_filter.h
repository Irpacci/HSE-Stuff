#ifndef BASE_FILTER_H
#define BASE_FILTER_H

#include <string>

#include "filter_setting.h"
#include "image.h"

class BaseFilter {
public:
    BaseFilter(){};
    virtual ~BaseFilter(){};

public:
    virtual void Apply(BMPImage& image) = 0;
};

#endif
