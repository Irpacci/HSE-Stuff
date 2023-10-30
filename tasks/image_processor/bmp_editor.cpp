#include "bmp_editor.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

#include "filter_production.h"
#include "pipeline.h"

void BMPEditor::Open(const std::string &filename) {
    if (file_.is_open()) {
        throw std::logic_error("File is already open.");
    }

    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    filename_ = filename;
    file_.open(filename_, std::ios_base::in | std::ios_base::binary);

    if (!file_.is_open()) {
        throw std::runtime_error("Cannot open file.");
    }
}

void BMPEditor::OpenOutput(const std::string &filename) {

    if (output_.is_open()) {
        throw std::logic_error("File is already open.");
    }

    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    std::ofstream tmp;
    tmp.open(filename);
    filename_output_ = filename;
    output_.open(filename_output_, std::ios_base::in | std::ios_base::binary);

    if (!output_.is_open()) {
        throw std::runtime_error("Cannot open output file.");
    }
}

void BMPEditor::Close() {
    file_.close();
    filename_.clear();
}

void BMPEditor::CloseOutput() {
    output_.close();
    filename_output_.clear();
}

void BMPEditor::ReadImage() {
    if (!IsOpen()) {
        throw std::logic_error("File is not open.");
    }

    // Всегда читаем с начала файла
    file_.seekg(0);
    image_.ReadBmp(file_);
}

void BMPEditor::WriteImage() {
    if (!IsOpen()) {
        throw std::logic_error("File is not open.");
    }

    // Всегда читаем с начала файла
    file_.seekg(0);
    image_.WriteBmp(output_);
}

void BMPEditor::GetCommands(char* commands[], int32_t size) {
    parser_.Parse(commands, size);
    filename_ = parser_.GetFilename();
    filename_output_ = parser_.GetOutput();
    Open(filename_);
    OpenOutput(filename_output_);
    ReadImage();
    std::vector<FilterSetting> parsed = parser_.GetParsed();
    FilterFactory factory;
    Pipeline pipeline;
    for (FilterSetting x : parsed) {
        pipeline.AddFilter(factory.Generate(x));
    }
    pipeline.Apply(image_);
    WriteImage();
}

BMPEditor::~BMPEditor() {
    Close();
}