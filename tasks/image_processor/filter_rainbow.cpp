#include "filter_rainbow.h"
#include "rgbmatrix.h"
#include "filter_grayscale.h"

const int32_t COEF = 6;
const float COEF2 = 2.0f;

static float HueToRGB(float v1, float v2, float v_h) {
    if (v_h < 0) {
        v_h++;
    }
    if (v_h > 1) {
        v_h--;
    }
    if ((COEF * v_h) < 1) {
        return (v1 + (v2 - v1) * COEF * v_h);
    }
    if ((2 * v_h) < 1) {
        return v2;
    }
    if ((3 * v_h) < 2) {
        return (v1 + (v2 - v1) * ((COEF2 / 3) - v_h) * 6);
    }
    return v1;
}

const int32_t CIRCLE = 360;
const int32_t MAX_INT8 = 255;
const float HALF = 0.5;

static RGB HSLToRGB(int32_t h, float s, float l) {
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    if (s == 0) {
        r = g = b = static_cast<unsigned char>(l * MAX_INT8);
    } else {
		float v2 = (l < HALF) ? (l * (1 + s)) : ((l + s) - (l * s));
		float v1 = 2 * l - v2;
        float hue = static_cast<float>(h) / CIRCLE;
        r = static_cast<unsigned char>(MAX_INT8 * HueToRGB(v1, v2, hue + (1.0f / 3)));
        g = static_cast<unsigned char>(MAX_INT8 * HueToRGB(v1, v2, hue));
        b = static_cast<unsigned char>(MAX_INT8 * HueToRGB(v1, v2, hue - (1.0f / 3)));
    }
    return RGB(r, g, b);
}



void RainbowFilter::Apply(BMPImage &image) {
    int32_t height = image.GetHeight();
    int32_t width = image.GetWidth();
    GrayscaleFilter grayscale;
    grayscale.Apply(image);
    RGBMatrix new_matrix(height, width, RGB(0, 0, 0));
    for (int32_t i = 0; i < height; i++) {
        for (int32_t j = 0; j < width; j++) {
            float intensity = image.GetElement(i, j).g;
            intensity /= (MAX_INT8 + 1);
            new_matrix[i][j] = HSLToRGB((j / rainbow_width_) % CIRCLE, intensity, intensity);
        }
    }
    image.SetMatrix(new_matrix);
}