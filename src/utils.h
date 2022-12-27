#include <stdlib.h>
#include <stdbool.h>

#include "definitions.h"

position* get_random_pos();

matrix* get_matrix();

bool are_positions_equal(position* pos1, position* pos2);

void setup_terminal();

unsigned int millisec_to_microsec(unsigned int micro_sec);
