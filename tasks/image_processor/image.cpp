#include "image.h"

const int32_t BASIC_OFFSET = 54;

void BMPImage::ReadBmp(std::fstream &flow) {
    ReadBmpHeader(flow);
    ReadDibHeader(flow);
    flow.read(reinterpret_cast<char *>(&elsedata), bmp_header_.offset - BASIC_OFFSET);
    ReadPixelArray(flow);
}

void BMPImage::ReadBmpHeader(std::fstream &flow) {
    // if (!file_) throw ...
    flow.read(reinterpret_cast<char *>(&bmp_header_), sizeof(BMPHeader));
    // if (!file_) throw ...

    // Проверяем корректность bmp_header_ прямо здесь
    if (bmp_header_.signature != BMP_SIGNATURE) {
        throw std::runtime_error("BMP File is not correct.");
    }
}

void BMPImage::ReadDibHeader(std::fstream &flow) {
    // if (!file_) throw ...
    flow.read(reinterpret_cast<char *>(&dib_header_), sizeof(DIBHeader));
    // if (!file_) throw ...

    // Проверяем корректность полей здесь... (bits_per_pixel)
}

void BMPImage::ReadPixelArray(std::fstream &flow) {
    RGBMatrix new_matrix(dib_header_.height, dib_header_.width, default_value);
    int32_t size_of_padding = (4 - (dib_header_.width * 3) % 4) % 4;
    int32_t padding_collector = 0;
    for (int32_t row_number = dib_header_.height - 1; row_number >= 0; row_number--) {
        flow.read(reinterpret_cast<char *>(&new_matrix.GetElement(row_number, 0)), dib_header_.width * sizeof(RGB));
        flow.read(reinterpret_cast<char *>(&padding_collector), size_of_padding);
    }
    pixel_array_ = new_matrix;
}

void BMPImage::WriteBmp(std::ofstream &flow) {
    flow.write(reinterpret_cast<char *>(&bmp_header_), sizeof(BMPHeader));
    flow.write(reinterpret_cast<char *>(&dib_header_), sizeof(DIBHeader));
    flow.write(reinterpret_cast<char *>(&elsedata), bmp_header_.offset - BASIC_OFFSET);
    int32_t size_of_padding = (4 - (dib_header_.width * 3) % 4) % 4;
    int32_t padding_collector;
    for (int32_t row_number = dib_header_.height - 1; row_number >= 0; row_number--) {
        flow.write(reinterpret_cast<char *>(&pixel_array_.GetElement(row_number, 0)), dib_header_.width * sizeof(RGB));
        flow.write(reinterpret_cast<char *>(&padding_collector), size_of_padding);
    }
}
