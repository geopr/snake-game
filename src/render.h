#include "definitions.h"
#include "linked-list.h"

void draw(matrix* matrix);

position* move(unsigned short MOVING_DIRECTION, position* pos);

void render_char(unsigned int char_code, position* pos, matrix* matrix);

position* get_random_apple_position(List* list);

void render_snake(List* list, matrix* matrix);

void clear_screen();

void render_game_over_screen();

