#include <stdio.h>

#include "definitions.h"
#include "render.h"
#include "input.h"
#include "utils.h"
#include "linked-list.h"

void draw(matrix* matrix) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      int n = matrix->m[row][col];

      switch (n) {
        case SNAKE_BODY:
          printf("s");
          break;

        case FIELD:
          printf("-");
          break;

        case APPLE:
          printf("*");
          break;
      }
    }

    printf("\n");
  }
}

int cycle(int i, int min, int max) {
  if (i < min) return max;
  if (i > max) return min;
  return i;
}

int cycle_col(int col) {
  return cycle(col, 0, COLS - 1);
}

int cycle_row(int row) {
  return cycle(row, 0, ROWS - 1);
}

position* move(unsigned short dir, position* pos) {
  position* next_pos = malloc(sizeof(position));
  next_pos->col = pos->col;
  next_pos->row = pos->row;

  switch (dir) {
    case LEFT_DIR:
      next_pos->col = cycle_col(next_pos->col - 1);
      break;

    case BOTTOM_DIR:
      next_pos->row = cycle_row(next_pos->row + 1);
      break;

    case TOP_DIR:
      next_pos->row = cycle_row(next_pos->row - 1);
      break;

    case RIGHT_DIR:
      next_pos->col = cycle_col(next_pos->col + 1);
      break;
  }

  return next_pos;
}

void render_char(unsigned int char_code, position* pos, matrix* matrix) {
  matrix->m[pos->row][pos->col] = char_code;
}

position* get_random_apple_position(List* list) {
  position* apple_pos = get_random_pos();

  while (includes(list, apple_pos)) {
    apple_pos = get_random_pos();
  }

  return apple_pos;
}

void clear_screen() {
  printf("\e[1;1H\e[2J");
}

void render_snake(List* list, matrix* matrix) {
  Node* current = list->first;

  while (current != NULL) {
    render_char(SNAKE_BODY, current->value, matrix);
    current = current->next;
  }
}

void render_game_over_screen() {
  clear_screen();
  printf("game over\n");
}

