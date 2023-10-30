#ifndef RGBMATRIX_H
#define RGBMATRIX_H

#include <cstddef>

#include "rgb.h"

class RGBMatrix {
public:
    class RGBRow {
        friend class RGBMatrix;

    public:
        RGB &operator[](size_t col) {
            return _owner->GetElement(_number, col);
        }

        const RGB &operator[](size_t col) const {
            return _owner->GetElement(_number, col);
        }

    protected:
        RGBRow(size_t number, RGBMatrix *owner) : _number{number}, _owner{owner} {
        }

    protected:
        size_t _number;
        RGBMatrix *_owner;
    };

    class ConstRGBRow {
        friend class RGBMatrix;

    public:
        const RGB &operator[](size_t col) const {
            return _owner->GetElement(_number, col);
        }

    protected:
        ConstRGBRow(size_t number, const RGBMatrix *owner) : _number{number}, _owner{owner} {
        }

    protected:
        size_t _number;
        const RGBMatrix *_owner;
    };

public:
    RGBMatrix() : _rows_num{0}, _cols_num{0}, _data{nullptr} {
    }

    RGBMatrix(size_t rows_num, size_t cols_num, RGB default_value = RGB{});

    RGBMatrix(const RGBMatrix &origin);

    RGBMatrix(RGBMatrix &&almost_corp);

    ~RGBMatrix();

    RGBMatrix &operator=(const RGBMatrix &rhs);

    RGBMatrix &operator=(RGBMatrix &&rhs);

    RGBRow operator[](size_t row) {
        return RGBRow{row, this};
    }

    ConstRGBRow operator[](size_t row) const {
        return ConstRGBRow{row, this};
    }

    /// Returns number of rows of the matrix
    size_t GetRowsNum() const {
        return _rows_num;
    }

    /// Returns number of columns of the matrix4
    size_t GetColsNum() const {
        return _cols_num;
    }

    /// Returns the pointer at the backstage for some reasons and different purposes
    const RGB* GetRawPtr() const {
        return _data;
    }

    size_t Offset(size_t row, size_t col) const {
        return row * _cols_num + col;
    }

    RGB& GetElement(int32_t row, int32_t col) {
        row = std::max(row, 0);
        row = std::min(row, static_cast<int32_t>(_rows_num) - 1);
        col = std::max(col, 0);
        col = std::min(col, static_cast<int32_t>(_cols_num) - 1);
        return _data[Offset(row, col)];
    }

    const RGB& GetElement(int32_t row, int32_t col) const {
        row = std::max(row, 0);
        row = std::min(row, static_cast<int32_t>(_rows_num) - 1);
        col = std::max(col, 0);
        col = std::min(col, static_cast<int32_t>(_cols_num) - 1);
        return _data[Offset(row, col)];
    }

    size_t GetRawDataSize() const {
        return _rows_num * _cols_num;
    }

protected:
    /// Обменивает местами атрибуты двух матриц, связанные с управлением динамического массива (ресурса)
    /// Must never fail
    static void Swap(RGBMatrix &lhs, RGBMatrix &rhs) noexcept;

protected:
    size_t _rows_num;
    size_t _cols_num;
    RGB *_data;
};

#endif  // RGBMATRIX_H
