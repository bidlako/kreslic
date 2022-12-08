//
// Created by biond on 08.10.2022.
//

#include <memory>
#include <fstream>
#include <iostream>
#include "canvas.h"

void Canvas::Draw(std::unique_ptr<Shape> shape) {
    m_shapes.push_back(std::move(shape));
}

void Canvas::Export_to_svg(std::string const &filename) const {
    std::ofstream file(filename);
    file << R"(<?xml version="1.0" encoding="UTF-8" standalone="no"?>)" << std::endl;
    file << "<svg width=\"" << m_width << "\" height=\"" << m_height
         << R"(" version="1.1" xmlns="http://www.w3.org/2000/svg">)" << std::endl;
    file << R"(<rect width="100%" height="100%" fill="white" />)" << std::endl;
    for (auto const &shape: m_shapes) {
        file << shape->Vectorize(SVG_BLACK, 1) << std::endl;
    }
    file << "</svg>" << std::endl;
}

void Canvas::Export_to_pgm(const std::string &filename) const {
    std::ofstream file(filename);
    file << "P2" << std::endl;
    file << m_width << " " << m_height << std::endl;
    file << "1" << std::endl;
    std::vector<std::vector<bool>> raster(m_width, std::vector<bool>(m_height, PGM_WHITE));
    for (auto const &shape: m_shapes) {
        for (auto const &pos: shape->Rasterize(2)) {
            raster[(int) pos.GetX()][(int) pos.GetY()] = PGM_BLACK;
        }
    }
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            file << raster[j][i] << " ";
        }
        file << std::endl;
    }
}

void Canvas::Transform(std::function<void(Shape &)> const &transformer) const {
    for (auto const &shape: m_shapes) {
        transformer(*shape);
    }
}

void Canvas::Set_Width(int width) {
    m_width = width;
}

void Canvas::Set_Height(int height) {
    m_height = height;
}
