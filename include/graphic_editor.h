//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_GRAPHIC_EDITOR_H
#define CPP_SP_01_GRAPHIC_EDITOR_H

#include <filesystem>
#include "canvas.h"

constexpr auto PGM_EXTENSION = ".pgm";
constexpr auto SVG_EXTENSION = ".svg";
constexpr auto TXT_EXTENSION = ".txt";

class GraphicEditor {
public:
    GraphicEditor(int width, int height);

    void Load_From_File(const std::filesystem::path &path);

    void Save_As(const std::filesystem::path &path) const;


private:
    Canvas m_canvas;
};


#endif //CPP_SP_01_GRAPHIC_EDITOR_H
