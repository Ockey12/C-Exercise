#include<curses.h>
#include<unistd.h>

#define ROW 3//段の数

typedef struct POINT{
  int row;
  int col;
} Point;

int draw_point(Point a, char c);

int main(void)
{
  int c1, c2, cc=1;
  int max_y, max_x;
  Point a;
  int x, y=1;
  char moji='Z';

  initscr();
  curs_set(0);
  getmaxyx(stdscr, max_y, max_x);

  if(max_x % 2 == 0){
    x=max_x/2;
  }else{
    x=(max_x+1)/2;
  }


  for(c1=0; c1<ROW; c1++){
    a.row=y;
    a.col=x;
    for(c2=0; c2<cc; c2++){
      draw_point(a, moji);
      a.col++;
      moji--;
      if(moji=='@'){//AまでいったらZに戻る
	moji='Z';
      }
    }
    y++;
    x--;
    cc=cc+2;
    moji='Z';
    sleep(1);
  }

  sleep(5);
  endwin();

  return 0;
}

  
int draw_point(Point a, char c)
{
  int status=0;
  int max_y, max_x;

  getmaxyx(stdscr, max_y, max_x);

  if(a.row<max_y && a.col<max_x){
    move(a.row, a.col);
    addch(c);
    refresh();
  }else{
    status=1;
  }

  return status; 
}
