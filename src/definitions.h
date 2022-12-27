#ifndef _DEFINED
#define _DEFINED

#define ROWS 40
#define COLS 100

#define SNAKE_BODY 0
#define FIELD 1
#define APPLE 2

typedef struct { 
  unsigned short col;
  unsigned short row;
} position;

typedef struct {
  unsigned short m[ROWS][COLS];
} matrix;

#endif
