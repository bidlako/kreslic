//
// Created by Ondřej Bidlák on 08.12.2022.
//

#ifndef CPP_SP_01_PARSER_H
#define CPP_SP_01_PARSER_H

#include <filesystem>
#include "canvas.h"

constexpr auto COMMENT_ID = "#";
constexpr auto RECTANGLE_ID = "rect";
constexpr auto CIRCLE_ID = "circle";
constexpr auto LINE_ID = "line";
constexpr auto TRANSLATE_ID = "translate";
constexpr auto SCALE_ID = "scale";
constexpr auto ROTATE_ID = "rotate";
constexpr auto TXT_EXTENSION = ".txt";


class Parser {
public:
    static Canvas Parse(const std::filesystem::path &path) ;

private:
    static void ParseLine(const std::string &line, Canvas &canvas) ;

    void HandleInstruction(const std::string &instruction, std::stringstream &ss, Canvas &canvas) const;
};


#endif //CPP_SP_01_PARSER_H
