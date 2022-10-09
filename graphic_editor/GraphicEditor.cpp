//
// Created by biond on 08.10.2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <filesystem>
#include "GraphicEditor.h"
#include "../shape/Shape.h"
#include "../shape/Rectangle.h"
#include "../shape/Circle.h"
#include "../shape/Line.h"


GraphicEditor::GraphicEditor(int width, int height) : m_canvas(width, height) {}

void GraphicEditor::Load_From_File(const std::string &path) {
    double x, y, x1, y1, x2, y2, r, w, h, f, a;
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
//    if (path.extension().string() != ".txt") {
//        throw std::runtime_error("File must be .txt");
//    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string instruction;
        ss >> instruction;
        if (instruction == "rect") {
            ss >> x >> y >> w >> h;
            m_canvas.Draw(std::make_unique<Rectangle>(x, y, w, h));
        } else if (instruction == "circle") {
            ss >> x >> y >> r;
            m_canvas.Draw(std::make_unique<Circle>(x, y, r));
        } else if (instruction == "line") {
            ss >> x1 >> y1 >> x2 >> y2;
            m_canvas.Draw(std::make_unique<Line>(x1, y1, x2, y2));
        } else if (instruction == "translate") {
            ss >> x >> y;
            m_canvas.Translate(x, y);
        } else if (instruction == "scale") {
            ss >> x >> y >> f;
            m_canvas.Scale(x, y, f);
        } else if (instruction == "rotate") {
            ss >> x >> y >> a;
            m_canvas.Rotate(x, y, a);
        } else {
            std::cout << instruction << std::endl;
            throw std::runtime_error("Invalid file format");
        }
    }
}

void GraphicEditor::Save_As(const std::string &path) const {
    std::string e = get_fextension(path);
    if (e == PGM_EXTENSION) {
        m_canvas.Export_to_pgm(path);
    } else if (e == SVG_EXTENSION) {
        m_canvas.Export_to_svg(path);
    } else {
        throw std::runtime_error("Invalid file format");
    }
}

std::string GraphicEditor::get_fextension(const std::string &filename) const {
    std::string extension = filename.substr(filename.find_last_of('.'));
    return extension;
}



