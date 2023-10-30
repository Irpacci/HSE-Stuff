#include "filter_blur.h"
#include "rgbmatrix.h"

#include <math.h>
#include <iostream>

const long double ONE_OVER_2PI = 0.15915494;
const long double ONE_OVER_E = 0.36787944;
const int32_t MAX_INT8 = 255;

void BlurFilter::Apply(BMPImage &image) {
    int32_t max_distance = ceil(sigma_ * 3);
    long double sigma_squared = sigma_ * sigma_;
    long double complete_fraction = ONE_OVER_2PI / sigma_squared;
    long double answers[max_distance + 1][max_distance + 1];
    for (int32_t i = 0; i <= max_distance; i++) {
        for (int32_t j = 0; j <= max_distance; j++) {
            long double power = i * i + j * j;
            power /= 2 * sigma_squared;
            long double end_value = pow(ONE_OVER_E, power);
            answers[i][j] = end_value * complete_fraction;
        }
    }
    int32_t height = image.GetHeight();
    int32_t width = image.GetWidth();
    RGBMatrix new_matrix(height, width, RGB());
    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            long double new_r = 0;
            long double new_g = 0;
            long double new_b = 0;
            for (int32_t new_i = std::max(0, i - max_distance); new_i < std::min(i + max_distance + 1, height);
                 new_i++) {
                for (int32_t new_j = std::max(0, j - max_distance); new_j < std::min(j + max_distance + 1, width);
                     new_j++) {
                    int32_t distance_from_i = abs(new_i - i);
                    int32_t distance_from_j = abs(new_j - j);
                    RGB current = image.GetElement(new_i, new_j);
                    long double end_fraction = answers[distance_from_i][distance_from_j];
                    new_r += end_fraction * current.r;
                    new_g += end_fraction * current.g;
                    new_b += end_fraction * current.b;
                }
            }
            uint8_t r = std::min(MAX_INT8, static_cast<int32_t>(round(new_r)));
            uint8_t g = std::min(MAX_INT8, static_cast<int32_t>(round(new_g)));
            uint8_t b = std::min(MAX_INT8, static_cast<int32_t>(round(new_b)));
            new_matrix[i][j] = RGB(r, g, b);
        }
    }
    image.SetMatrix(new_matrix);
}