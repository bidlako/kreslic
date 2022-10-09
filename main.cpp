#include <iostream>
#include "graphic_editor/GraphicEditor.h"


int handle_args(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <input file> <output file> <size>" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    auto editor = GraphicEditor(160, 160);
    handle_args(argc, argv);
    editor.Load_From_File(argv[1]);
    editor.Save_As(argv[2]);
}

