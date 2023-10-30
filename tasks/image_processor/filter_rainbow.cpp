#include "filter_rainbow.h"
#include "rgbmatrix.h"
#include "filter_grayscale.h"

static float HueToRGB(float v1, float v2, float vH) {
    if (vH < 0) {
        vH++;
    }
    if (vH > 1) {
        vH--;
    }
    if ((6 * vH) < 1) {
        return (v1 + (v2 - v1) * 6 * vH);
    }
    if ((2 * vH) < 1) {
        return v2;
    }
    if ((3 * vH) < 2) {
        return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
    }
    return v1;
}

static RGB HSLToRGB(int32_t H, float S, float L) {
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    if (S == 0) {
        r = g = b = (unsigned char)(L * 255);
    } else {
        float v1, v2;
        float hue = (float)H / 360;
        v2 = (L < 0.5) ? (L * (1 + S)) : ((L + S) - (L * S));
        v1 = 2 * L - v2;
        r = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
        g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
        b = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
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
            intensity /= 256.0;
            new_matrix[i][j] = HSLToRGB((j / rainbow_width_) % 360, intensity, intensity);
        }
    }
    image.SetMatrix(new_matrix);
}