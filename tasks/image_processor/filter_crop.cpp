#include "filter_crop.h"
#include "rgbmatrix.h"

void CropFilter::Apply(BMPImage &image) {
    uint32_t size = image.GetSize();
    size_t old_width = image.GetWidth();
    size_t old_height = image.GetHeight();
    size_t size_of_padding = (4 - (old_width * 3) % 4) % 4;
    size -= (old_width + size_of_padding) * old_height;
    size_t height = std::min(new_height_, static_cast<int32_t>(old_height));
    size_t width = std::min(new_width_, static_cast<int32_t>(old_width));
    RGBMatrix new_matrix(height, width, RGB());
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            new_matrix[i][j] = image.GetElement(i, j);
        }
    }
    size_of_padding = (4 - (width * 3) % 4) % 4;
    size += (size_of_padding + width) * height;
    image.SetSize(size);
    image.SetHeight(height);
    image.SetWidth(width);
    image.SetMatrix(new_matrix);
}