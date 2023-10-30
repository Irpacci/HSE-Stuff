#include "filter_edge.h"
#include "filter_grayscale.h"
#include "rgbmatrix.h"

const RGB BLACK(0, 0, 0);
const RGB WHITE(255, 255, 255);

void EdgeFilter::Apply(BMPImage &image) {
    GrayscaleFilter f;
    f.Apply(image);
    int32_t height = image.GetHeight();
    int32_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            int32_t new_color = 4 * image.GetElement(i, j).r;
            std::vector<uint8_t> adjacent_elements = {image.GetElement(i - 1, j).r, image.GetElement(i + 1, j).r,
                                                      image.GetElement(i, j - 1).r, image.GetElement(i, j + 1).r};
            for (uint8_t color : adjacent_elements) {
                new_color -= color;
            }
            if (new_color > threshold_) {
                new_matrix[i][j] = WHITE;
            } else {
                new_matrix[i][j] = BLACK;
            }
        }
    }
    image.SetMatrix(new_matrix);
}