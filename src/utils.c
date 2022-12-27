#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>

#include "definitions.h"
#include "utils.h"

position* get_random_pos() {
  position* pos = malloc(sizeof(position));

  pos->col = rand() % COLS;
  pos->row = rand() % ROWS;

  return pos;
}

matrix* get_matrix() {
  matrix* result = malloc(sizeof(matrix));

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      result->m[row][col] = FIELD;
    }
  }
  
  return result;
};

bool are_positions_equal(position* pos1, position* pos2){
  return (
    pos1->row == pos2->row &&
    pos1->col == pos2->col
  );
}

void setup_terminal() {
  struct termios opts;

  tcgetattr(STDIN_FILENO, &opts);

  opts.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &opts);
}

unsigned int millisec_to_microsec(unsigned int milli_sec) {
  return milli_sec * 1000;
}
