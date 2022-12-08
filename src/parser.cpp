//
// Created by Ondřej Bidlák on 08.12.2022.
//

#include "parser.h"
#include "rectangle.h"
#include "circle.h"
#include "line.h"
#include "shape.h"
#include <fstream>
#include <sstream>
#include <iostream>

Canvas Parser::Parse(const std::filesystem::path &path) {
    int instruction_count = 0;
    Canvas canvas;

    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("File not found");
    }
    if (path.extension().string() != TXT_EXTENSION) {
        throw std::runtime_error("File must be .txt");
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        auto p = line.find(COMMENT_ID);
        if (p != std::string::npos) {
            line = line.substr(0, p);
        }
        ParseLine(line, canvas);
        instruction_count++;
    }
    std::cout << "Ok \n" << instruction_count << std::endl;

    return canvas;

}

void Parser::ParseLine(const std::string &line, Canvas &canvas) {
    double x, y, x1, y1, x2, y2, r, w, h, f, a;
    std::stringstream ss(line);
    std::string instruction;
    ss >> instruction;
    if (instruction == RECTANGLE_ID) {
        ss >> x >> y >> w >> h;
        canvas.Draw(std::make_unique<Rectangle>(x, y, w, h));
    } else if (instruction == "circle") {
        ss >> x >> y >> r;
        canvas.Draw(std::make_unique<Circle>(x, y, r));

    } else if (instruction == "line") {
        ss >> x1 >> y1 >> x2 >> y2;
        canvas.Draw(std::make_unique<Line>(x1, y1, x2, y2));

    } else if (instruction == "translate") {
        ss >> x >> y;
        canvas.Transform([&](Shape &shape) {
            shape.Translate({x, y});
        });

    } else if (instruction == "scale") {
        ss >> x >> y >> f;
        canvas.Transform([&](Shape &shape) {
            shape.Scale({x, y}, f);
        });

    } else if (instruction == "rotate") {
        ss >> x >> y >> a;
        canvas.Transform([&](Shape &shape) {
            shape.Rotate({x, y}, a);
        });

    } else {
        std::cout << instruction << std::endl;
        throw std::runtime_error("Invalid file format");
    }
}
