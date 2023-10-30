#ifndef BMP_EDITOR_H
#define BMP_EDITOR_H

#include <cstdint>
#include <string>
#include <fstream>

#include "image.h"
#include "parser.h"

class BMPEditor {
public:
    BMPEditor() {
    }

    ~BMPEditor();

    /// Открывает файл с переданным именем файла
    void Open(const std::string &filename);

    void OpenOutput(const std::string &filename);

    /// Закрывает файл
    void Close();

    void CloseOutput();

    void GetCommands(char *commands[], int32_t size);
    /// Читает открытый BMP файл
    void ReadImage();

    void WriteImage();

    bool IsOpen() const {
        return file_.is_open();
    }

    const std::string &GetFilename() const {
        return filename_;
    }

protected:
    std::string filename_;
    std::fstream file_;
    std::string filename_output_;
    std::ofstream output_;
    Parser parser_;
    BMPImage image_;
};

#endif
