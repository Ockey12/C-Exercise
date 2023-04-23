//最低30*30が必要
//画面の大きさが足りない場合は強制終了
#include<curses.h>
#include<unistd.h>

#define OBJECT 3
#define HEN 10

typedef struct POINT{
  int row;
  int col;
} Point;

typedef struct BOX{
  Point s;
  int dx;//長さ
  int dy;
} Box;

int draw_point(Point a, char c);

int draw_box(Box a, char c);

int fill_box(Box a, char c);

int main(void)
{
  Box a;
  char C;
  int max_x, max_y;
  int c1, c2, cc=0, count;
  int x, y;

  C='A';

  initscr();
  curs_set(0);

  a.dx=HEN;
  a.dy=HEN;

  x=0;
  y=0;
  a.s.row=y;

  getmaxyx(stdscr, max_y, max_x);

  if(HEN*3<max_x && HEN*3<max_y){
    for(c1=0; c1<OBJECT; c1++){
      a.s.col=x;
      for(c2=0; c2<OBJECT; c2++){
	if(cc%2==0){
	  draw_box(a, C);
	  a.s.col=a.s.col+HEN;
	}else{
	  fill_box(a, C);
	  a.s.col=a.s.col+HEN;
	}
	cc++;
      }
      a.s.row=a.s.row+HEN;
    }
    sleep(10);
    endwin();
  }else{
    endwin();
    return 1;
  }

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

int draw_box(Box a, char c)
{
  int status=0;
  int max_x, max_y;
  Point p;
  int x, y;
  int c1, c2;

  initscr();

  getmaxyx(stdscr, max_y, max_x);

  if(a.s.col+a.dx-1<max_x && a.s.row+a.dy-1<max_y){
    x=a.s.col;
    y=a.s.row;  
    for(c1=0; c1<a.dy; c1++){
      p.col=x;
      p.row=y;
      if(c1==0 || c1==a.dx-1){
	for(c2=0; c2<a.dx; c2++){
	  draw_point(p, c);
	  p.col++;
	}
      }else{	
	draw_point(p, c);
	p.col=p.col+a.dx-1;
	draw_point(p, c);
      }
      y++;
    }
  }else{
    status=1;
  }
      
  return status;
}

int fill_box(Box a, char c)
{
  int status=0;
  int max_x, max_y;
  Point p;
  int x, y;
  int c1, c2;

  initscr();

  getmaxyx(stdscr, max_y, max_x);

  if(a.s.col+a.dx-1<max_x && a.s.row+a.dy-1<max_y){
    x=a.s.col;
    y=a.s.row;  
    for(c1=0; c1<a.dy; c1++){
      p.col=x;
      p.row=y; 
	for(c2=0; c2<a.dx; c2++){
	  draw_point(p, c);
	  p.col++;
	}
      y++;
    }
  }else{
    status=1;
  }
      
  return status;
}
