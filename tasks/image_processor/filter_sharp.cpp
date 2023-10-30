#include "filter_sharp.h"
#include "rgbmatrix.h"

const int32_t COEF = 5;
const int32_t MAX_INT8 = 255;

void SharpFilter::Apply(BMPImage &image) {
    int32_t height = image.GetHeight();
    int32_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            RGB new_element = image.GetElement(i, j);
            std::vector<RGB> adjacent_elements = {image.GetElement(i - 1, j), image.GetElement(i + 1, j),
                                                  image.GetElement(i, j - 1), image.GetElement(i, j + 1)};
            int32_t new_r = COEF * new_element.r;
            int32_t new_g = COEF * new_element.g;
            int32_t new_b = COEF * new_element.b;
            for (RGB const &rgb : adjacent_elements) {
                new_r -= rgb.r;
                new_g -= rgb.g;
                new_b -= rgb.b;
            }
            new_element.r = std::max(0, std::min(MAX_INT8, new_r));
            new_element.g = std::max(0, std::min(MAX_INT8, new_g));
            new_element.b = std::max(0, std::min(MAX_INT8, new_b));
            new_matrix[i][j] = new_element;
        }
    }
    image.SetMatrix(new_matrix);
}