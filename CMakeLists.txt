cmake_minimum_required(VERSION 3.19)
project(cpp_sp_01)

set(CMAKE_CXX_STANDARD 14)


add_executable(cpp_sp_01 main.cpp
        matrix/Matrix.cpp matrix/Matrix.h
         shape/Shape.h
        canvas/Canvas.cpp canvas/Canvas.h
        position/Position.cpp position/Position.h
        shape/Line.cpp shape/Line.h
        shape/Circle.cpp shape/Circle.h
        shape/Rectangle.cpp shape/Rectangle.h
        graphic_editor/GraphicEditor.cpp graphic_editor/GraphicEditor.h)