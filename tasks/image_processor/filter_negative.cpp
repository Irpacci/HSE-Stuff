#include "filter_negative.h"
#include "rgbmatrix.h"

void NegativeFilter::Apply(BMPImage &image) {
    size_t height = image.GetHeight();
    size_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            RGB new_element = image.GetElement(i, j);
            new_element.r = 256 - new_element.r;
            new_element.g = 256 - new_element.g;
            new_element.b = 256 - new_element.b;
            new_matrix[i][j] = new_element;
        }
    }
    image.SetMatrix(new_matrix);
}