#ifndef RGBMATRIX_H
#define RGBMATRIX_H

#include <cstddef>

#include "rgb.h"

class RGBMatrix {
public:
    class RGBRow {
        friend class RGBMatrix;

    public:
        RGB &operator[](int32_t col) {
            return _owner->GetElement(_number, col);
        }

        const RGB &operator[](int32_t col) const {
            return _owner->GetElement(_number, col);
        }

    protected:
        RGBRow(int32_t number, RGBMatrix *owner) : _number{number}, _owner{owner} {
        }

    protected:
        int32_t _number;
        RGBMatrix *_owner;
    };

    class ConstRGBRow {
        friend class RGBMatrix;

    public:
        const RGB &operator[](int32_t col) const {
            return _owner->GetElement(_number, col);
        }

    protected:
        ConstRGBRow(int32_t number, const RGBMatrix *owner) : _number{number}, _owner{owner} {
        }

    protected:
        int32_t _number;
        const RGBMatrix *_owner;
    };

public:
    RGBMatrix() : _rows_num{0}, _cols_num{0}, _data{nullptr} {
    }

    RGBMatrix(int32_t rows_num, int32_t cols_num, RGB default_value = RGB{});

    RGBMatrix(const RGBMatrix &origin);

    RGBMatrix(RGBMatrix &&almost_corp);

    ~RGBMatrix();

    RGBMatrix &operator=(const RGBMatrix &rhs);

    RGBMatrix &operator=(RGBMatrix &&rhs);

    RGBRow operator[](int32_t row) {
        return RGBRow{row, this};
    }

    ConstRGBRow operator[](int32_t row) const {
        return ConstRGBRow{row, this};
    }

    /// Returns number of rows of the matrix
    int32_t GetRowsNum() const {
        return _rows_num;
    }

    /// Returns number of columns of the matrix4
    int32_t GetColsNum() const {
        return _cols_num;
    }

    /// Returns the pointer at the backstage for some reasons and different purposes
    const RGB *GetRawPtr() const {
        return _data;
    }

    int32_t Offset(int32_t row, int32_t col) const {
        return row * _cols_num + col;
    }

    RGB &GetElement(int32_t row, int32_t col) {
        row = std::max(row, 0);
        row = std::min(row, static_cast<int32_t>(_rows_num) - 1);
        col = std::max(col, 0);
        col = std::min(col, static_cast<int32_t>(_cols_num) - 1);
        return _data[Offset(row, col)];
    }

    const RGB &GetElement(int32_t row, int32_t col) const {
        row = std::max(row, 0);
        row = std::min(row, static_cast<int32_t>(_rows_num) - 1);
        col = std::max(col, 0);
        col = std::min(col, static_cast<int32_t>(_cols_num) - 1);
        return _data[Offset(row, col)];
    }

    int32_t GetRawDataSize() const {
        return _rows_num * _cols_num;
    }

protected:
    /// Обменивает местами атрибуты двух матриц, связанные с управлением динамического массива (ресурса)
    /// Must never fail
    static void Swap(RGBMatrix &lhs, RGBMatrix &rhs) noexcept;

protected:
    int32_t _rows_num;
    int32_t _cols_num;
    RGB *_data;
};

#endif  // RGBMATRIX_H
