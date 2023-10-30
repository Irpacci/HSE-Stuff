#include "filter_negative.h"
#include "rgbmatrix.h"

const int32_t MAX_INT8 = 255;

void NegativeFilter::Apply(BMPImage &image) {
    int32_t height = image.GetHeight();
    int32_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            RGB new_element = image.GetElement(i, j);
            new_element.r = MAX_INT8 - new_element.r;
            new_element.g = MAX_INT8 - new_element.g;
            new_element.b = MAX_INT8 - new_element.b;
            new_matrix[i][j] = new_element;
        }
    }
    image.SetMatrix(new_matrix);
}