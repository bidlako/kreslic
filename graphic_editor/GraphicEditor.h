//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_GRAPHICEDITOR_H
#define CPP_SP_01_GRAPHICEDITOR_H

#include <filesystem>
#include "../canvas/Canvas.h"

constexpr auto PGM_EXTENSION = ".pgm";
constexpr auto SVG_EXTENSION = ".svg";
constexpr auto TXT_EXTENSION = ".txt";

class GraphicEditor {
public:
    GraphicEditor(int width, int height);

    void Load_From_File(const std::string &path);

    void Save_As(std::string const &filename) const;


private:
    Canvas m_canvas;

    std::string get_fextension(std::string const &filename) const;

};


#endif //CPP_SP_01_GRAPHICEDITOR_H
