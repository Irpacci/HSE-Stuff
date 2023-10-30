#include "filter_grayscale.h"
#include "rgbmatrix.h"

#include <math.h>

const double R_COEF = 0.299;
const double G_COEF = 0.587;
const double B_COEF = 0.114;

void GrayscaleFilter::Apply(BMPImage &image) {
    size_t height = image.GetHeight();
    size_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            RGB new_element = image.GetElement(i, j);
            double new_color = R_COEF * new_element.r + G_COEF * new_element.g + B_COEF * new_element.b;
            new_element.r = new_element.g = new_element.b = static_cast<uint8_t>(round(new_color));
            new_matrix[i][j] = new_element;
        }
    }
    image.SetMatrix(new_matrix);
}