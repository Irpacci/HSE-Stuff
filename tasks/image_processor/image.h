#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include <string>

#include "rgbmatrix.h"

const int32_t EXTRA_SIZE = 256;

class BMPImage {
public:
    static const uint16_t BMP_SIGNATURE = 0x4D42;  // BM
    RGB default_value = {0, 0, 0};
    char elsedata[EXTRA_SIZE];
    struct BMPHeader {
        uint16_t signature;
        uint32_t size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;
    } __attribute__((packed));

    struct DIBHeader {
        uint32_t header_size;
        int32_t width;
        int32_t height;
        uint16_t color_planes_num;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t image_size;
        int32_t hor_res;
        int32_t ver_res;
        uint32_t colors_num;
        uint32_t important_colors_num;
    } __attribute__((packed));

    void ReadBmp(std::fstream& flow);

    void WriteBmp(std::ofstream& flow);

    RGB& GetElement(int32_t row, int32_t col) {
        return pixel_array_.GetElement(row, col);
    }

    int32_t GetHeight() {
        return pixel_array_.GetRowsNum();
    }

    int32_t GetWidth() {
        return pixel_array_.GetColsNum();
    }

    uint32_t const GetSize() const {
        return bmp_header_.size;
    }

    void SetHeight(int32_t height) {
        dib_header_.height = height;
    }

    void SetWidth(int32_t width) {
        dib_header_.width = width;
    }

    void SetSize(uint32_t size) {
        bmp_header_.size = size;
    }

    void SetMatrix(RGBMatrix matrix) {
        pixel_array_ = matrix;
    }

protected:
    void ReadBmpHeader(std::fstream& flow);
    void ReadDibHeader(std::fstream& flow);
    void ReadPixelArray(std::fstream& flow);

protected:
    BMPHeader bmp_header_;
    DIBHeader dib_header_;
    RGBMatrix pixel_array_;
};

#endif