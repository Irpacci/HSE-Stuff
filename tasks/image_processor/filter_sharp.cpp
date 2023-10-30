#include "filter_sharp.h"
#include "rgbmatrix.h"

void SharpFilter::Apply(BMPImage &image) {
    size_t height = image.GetHeight();
    size_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            RGB new_element = image.GetElement(i, j);
            std::vector<RGB> adjacent_elements = {image.GetElement(i - 1, j), image.GetElement(i + 1, j),
                                                  image.GetElement(i, j - 1), image.GetElement(i, j + 1)};
            int32_t new_r = 5 * new_element.r;
            int32_t new_g = 5 * new_element.g;
            int32_t new_b = 5 * new_element.b;
            for (RGB rgb : adjacent_elements) {
                new_r -= rgb.r;
                new_g -= rgb.g;
                new_b -= rgb.b;
            }
            new_element.r = std::max(0, std::min(255, new_r));
            new_element.g = std::max(0, std::min(255, new_g));
            new_element.b = std::max(0, std::min(255, new_b));
            new_matrix[i][j] = new_element;
        }
    }
    image.SetMatrix(new_matrix);
}