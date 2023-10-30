#include "rgbmatrix.h"

#include <stdexcept>
#include <tuple>

RGBMatrix::RGBMatrix(int32_t rows_num, int32_t cols_num, RGB default_value) : RGBMatrix() {
    if (rows_num == 0 && cols_num == 0) {
        return;
    }

    if (rows_num == 0 || cols_num == 0) {
        throw std::logic_error("Invalid size of matrix, rows_num=0 or cols_num=0, but not both");
    }

    _rows_num = rows_num;
    _cols_num = cols_num;
    _data = new RGB[GetRawDataSize()];
    std::fill(_data, _data + GetRawDataSize(), default_value);
}

RGBMatrix::RGBMatrix(const RGBMatrix &origin)  //   : RGBMatrix(origin._rows_num, origin._cols_num)
    : _rows_num(origin._rows_num),
      _cols_num(origin._cols_num),
      _data(origin._data ? new RGB[origin.GetRawDataSize()] : nullptr) {
    if (_data) {
        std::copy(origin._data, origin._data + GetRawDataSize(), _data);
    }
}

RGBMatrix::RGBMatrix(RGBMatrix &&almost_corp)
    : _rows_num(almost_corp._rows_num), _cols_num(almost_corp._cols_num), _data(almost_corp._data) {
    almost_corp._rows_num = 0;
    almost_corp._cols_num = 0;
    almost_corp._data = nullptr;
}

RGBMatrix::~RGBMatrix() {
    delete[] _data;
}

RGBMatrix &RGBMatrix::operator=(const RGBMatrix &rhs) {
    if (this == &rhs) {
        return *this;
    }
    RGBMatrix tmp = rhs;
    Swap(*this, tmp);
    return *this;
}

RGBMatrix &RGBMatrix::operator=(RGBMatrix &&rhs) {
    delete[] _data;

    _rows_num = rhs._rows_num;
    _cols_num = rhs._cols_num;
    _data = rhs._data;
    rhs._rows_num = 0;
    rhs._cols_num = 0;
    rhs._data = nullptr;

    return *this;
}

void RGBMatrix::Swap(RGBMatrix &lhs, RGBMatrix &rhs) noexcept {
    std::swap(lhs._rows_num, rhs._rows_num);
    std::swap(lhs._cols_num, rhs._cols_num);
    std::swap(lhs._data, rhs._data);
}
