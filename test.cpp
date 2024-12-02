#include <stdio.h>

#include "Color-printf/color_printf.h"

int main() {
    color_printf(BLUE_COLOR, BOLD, "BLUE_COLOR\n");
    color_printf(MAGENTA_COLOR, BOLD, "MAGENTA_COLOR\n");
    color_printf(CYAN_COLOR, BOLD, "CYAN_COLOR\n");
    color_printf(WHITE_COLOR, BOLD, "WHITE_COLOR\n");
}
