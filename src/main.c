#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "definitions.h"
#include "utils.h"
#include "render.h" 
#include "input.h"
#include "linked-list.h"

int main() {
  setup_terminal();

  matrix* matrix = get_matrix();
  List* snake_list = init_list();

  push_back(snake_list, get_random_pos());

  position* apple_pos = get_random_apple_position(snake_list);
  render_char(APPLE, apple_pos, matrix);

  unsigned short MOVING_DIRECTION = RIGHT_DIR;

  while (true) {
    clear_screen();

    handle_input(&MOVING_DIRECTION);

    render_snake(snake_list, matrix);

    draw(matrix);

    position* first_snake_pos = snake_list->first->value;
    render_char(FIELD, first_snake_pos, matrix);

    position* last_snake_pos = snake_list->last->value;

    delete_start(snake_list);

    position* next_snake_pos = move(MOVING_DIRECTION, last_snake_pos);

    if (includes(snake_list, next_snake_pos)) {
      render_game_over_screen();
      break;
    }

    push_back(snake_list, next_snake_pos);

    if (are_positions_equal(last_snake_pos, apple_pos)) {
      apple_pos = get_random_apple_position(snake_list);
      render_char(APPLE, apple_pos, matrix);

      position* next_pos = move(MOVING_DIRECTION, next_snake_pos);
      push_back(snake_list, next_pos);
    }

    usleep(millisec_to_microsec(100));
  }

  return 0;
}

