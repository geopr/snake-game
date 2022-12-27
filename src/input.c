#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "input.h"

bool is_vertial_dir(unsigned short* dir) {
  return (*dir & VERTICAL_DIR) > 0;
}

bool is_horizontal_dir(unsigned short* dir) {
  return (*dir & HORIZONTAL_DIR) > 0;
}

void change_direction(unsigned short* dir) {
  int char_code = getchar();

  switch (char_code) {
    // left (h)
    case 104:
      if (is_horizontal_dir(dir)) return;

      *dir = LEFT_DIR;

      break;

    // bottom (j)
    case 106:
      if (is_vertial_dir(dir)) return;

      *dir = BOTTOM_DIR;

      break;

    // top (k)
    case 107:
      if (is_vertial_dir(dir)) return;

      *dir = TOP_DIR;

      break;

    // right (l)
    case 108:
      if (is_horizontal_dir(dir)) return;

      *dir = RIGHT_DIR;

      break;
  }
}

void handle_input(unsigned short* current_direction) {
  fd_set fds;

  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);

  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

  if (FD_ISSET(STDIN_FILENO, &fds)) {
    change_direction(current_direction);
  }
}
