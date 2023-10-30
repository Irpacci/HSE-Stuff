#include <cassert>
#include <iostream>

#include "bmp_editor.h"

int32_t main(int32_t argc, char* argv[]) {
    BMPEditor bmp_ed;
    bmp_ed.GetCommands(argv, argc);
}