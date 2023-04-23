#include <curses.h>
#include <unistd.h>

typedef struct POINT{
  int row;
  int col;
} Point;

int draw_point( Point a, char c ) {
  int status=0;

  getmaxyx(stdscr, row_max, col_max);

  if(a.row<row_max && a.col<col_max){
    move(a.row, a.col);
    addch(c);
    refresh();
  }else{
    status=1;
  }

  return status; 
}
