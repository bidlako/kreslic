//
// Created by biond on 08.10.2022.
//

#include <memory>
#include <fstream>
#include <iostream>
#include "Canvas.h"

Canvas::Canvas(int width, int height) : m_width(width), m_height(height) {}

void Canvas::Draw(std::unique_ptr<Shape> shape) {
    m_shapes.push_back(std::move(shape));
}

void Canvas::Translate(double x, double y) const {
    for (auto const &shape : m_shapes) {
        shape->Translate({x, y});
    }
}

void Canvas::Scale(double x, double y, double f) const {
    for (auto const &shape : m_shapes) {
        shape->Scale({x, y}, f);
    }
}

void Canvas::Rotate(double x, double y, double angle) const {
    for (auto const &shape : m_shapes) {
        shape->Rotate({x, y}, angle);
    }
}

void Canvas::Export_to_svg(std::string const &filename) const {
    std::ofstream file(filename);
    file << R"(<?xml version="1.0" encoding="UTF-8" standalone="no"?>)" << std::endl;
    file << "<svg width=\"" << m_width << "\" height=\"" << m_height
         << R"(" version="1.1" xmlns="http://www.w3.org/2000/svg">)" << std::endl;
    file << R"(<rect width="100%" height="100%" fill="white" />)" << std::endl;
    for (auto const &shape : m_shapes) {
        file << shape->Vectorize("black", 1) << std::endl;
    }
    file << "</svg>" << std::endl;

}

void Canvas::Export_to_pgm(const std::string &filename) const {
    std::ofstream file(filename);
    file << "P2" << std::endl;
    file << m_width << " " << m_height << std::endl;
    file << "1" << std::endl;
    std::vector<std::vector<bool>> raster(m_width, std::vector<bool>(m_height, true));
    for (auto const &shape : m_shapes) {
        for (auto const &pos : shape->Rasterize(2)) {
            raster[(int) pos.GetX()][(int) pos.GetY()] = false;
        }
    }
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            file << raster[j][i] << " ";
        }
        file << std::endl;
    }

}

