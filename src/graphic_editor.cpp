//
// Created by biond on 08.10.2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <filesystem>
#include "graphic_editor.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"


GraphicEditor::GraphicEditor(int width, int height) : m_canvas(width, height) {}

void GraphicEditor::Load_From_File(const std::filesystem::path &path) {
    int instruction_count = 0;
    double x, y, x1, y1, x2, y2, r, w, h, f, a;
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    if (path.extension().string() != TXT_EXTENSION) {
        throw std::runtime_error("File must be .txt");
    }
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
            m_canvas.Transform([&](Shape &shape) {
                shape.Translate({x, y});
            });

        } else if (instruction == "scale") {
            ss >> x >> y >> f;
            m_canvas.Transform([&](Shape &shape) {
                shape.Scale({x, y}, f);
            });

        } else if (instruction == "rotate") {
            ss >> x >> y >> a;
            m_canvas.Transform([&](Shape &shape) {
                shape.Rotate({x, y}, a);
            });

        } else {
            std::cout << instruction << std::endl;
            throw std::runtime_error("Invalid file format");
        }
        instruction_count++;
    }
    std::cout << "Ok \n" << instruction_count  << std::endl;
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



