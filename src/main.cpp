#include <iostream>
#include <tuple>
#include <filesystem>
#include "graphic_editor.h"

typedef std::tuple<std::filesystem::path, std::filesystem::path, int, int> args;

args parse_args(int argc, char *argv[]) {
    if (argc != 4) {
        throw std::invalid_argument(
                "Invalid number of arguments \n Usage: <input file> <output file> <width>x<height>");
    }
    auto size = std::string(argv[3]);
    auto pos = size.find('x');
    if (pos == std::string::npos) {
        throw std::invalid_argument("Invalid size format");
    }
    auto width = std::stoi(size.substr(0, pos));
    auto height = std::stoi(size.substr(pos + 1));

    return std::make_tuple(argv[1], argv[2], width, height);
}

int main(int argc, char *argv[]) {
    auto [input_f, output_f, width, height] = parse_args(argc, argv);
    auto editor = GraphicEditor();
    editor.Set_Canvas_Size(width, height);
    editor.Load_From_File(input_f);
    editor.Save_As(output_f);
}

