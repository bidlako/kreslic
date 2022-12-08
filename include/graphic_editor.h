//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_GRAPHIC_EDITOR_H
#define CPP_SP_01_GRAPHIC_EDITOR_H

#include <filesystem>
#include "canvas.h"
#include "parser.h"

constexpr auto PGM_EXTENSION = ".pgm";
constexpr auto SVG_EXTENSION = ".svg";

class GraphicEditor {
public:
    void Load_From_File(const std::filesystem::path &path);

    void Save_As(const std::filesystem::path &path) const;

    void Set_Canvas_Size(int width, int height);


private:
    Canvas m_canvas;
    Parser m_parser;
    int m_width{};
    int m_height{};
};


#endif //CPP_SP_01_GRAPHIC_EDITOR_H
