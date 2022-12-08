//
// Created by biond on 08.10.2022.
//
#include <memory>
#include <filesystem>
#include "graphic_editor.h"
#include "shape.h"


void GraphicEditor::Load_From_File(const std::filesystem::path &path) {
    m_canvas = Parser::Parse(path);
}

void GraphicEditor::Save_As(const std::filesystem::path &path) const {
    auto e = path.extension().string();
    if (e == PGM_EXTENSION) {
        m_canvas.Export_to_pgm(path);
    } else if (e == SVG_EXTENSION) {
        m_canvas.Export_to_svg(path);
    } else {
        throw std::runtime_error("Invalid file format");
    }
}

void GraphicEditor::Set_Canvas_Size(int width, int height) {
    m_canvas.Set_Width(width);
    m_canvas.Set_Height(height);
}



