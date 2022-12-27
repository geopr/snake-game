#ifndef _INPUT_DEF
#define _INPUT_DEF

#define LEFT_DIR 2
#define RIGHT_DIR 4
#define TOP_DIR 8
#define BOTTOM_DIR 16

#define HORIZONTAL_DIR (LEFT_DIR | RIGHT_DIR)
#define VERTICAL_DIR (TOP_DIR | BOTTOM_DIR)

void handle_input(unsigned short* current_direction);

#endif
