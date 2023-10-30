#include "filter_edge.h"
#include "filter_grayscale.h"
#include "rgbmatrix.h"

void EdgeFilter::Apply(BMPImage &image) {
    GrayscaleFilter f;
    f.Apply(image);
    RGB black(0, 0, 0);
    RGB white(255, 255, 255);
    size_t height = image.GetHeight();
    size_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            int32_t new_color = 4 * image.GetElement(i, j).r;
            std::vector<uint8_t> adjacent_elements = {image.GetElement(i - 1, j).r, image.GetElement(i + 1, j).r,
                                                      image.GetElement(i, j - 1).r, image.GetElement(i, j + 1).r};
            for (uint8_t color : adjacent_elements) {
                new_color -= color;
            }
            if (new_color > threshold_) {
                new_matrix[i][j] = white;
            } else {
                new_matrix[i][j] = black;
            }
        }
    }
    image.SetMatrix(new_matrix);
}