/* w:上に移動,s:下に移動,d:右に移動,a:左に移動,q:終了,画面外に出ると終了*/
#include <curses.h>
#include <unistd.h>
#define XHEN 15
#define YHEN 10
#define WAIT 40000

typedef struct POINT{
  int x;
  int y;
} Point;

typedef struct BOX{
  Point s;           // 左上の座標
  int   dx;          // ｘ方向の辺の長さ
  int   dy;          // ｙ方向の辺の長さ
} Box;

int draw_point( Point a, char c ); //プロトタイプ宣言

int fill_box(Box a, char c);

int main(void)
{
 Box a;
 char c;
 int max_x, max_y;
 char key;

 c='W';

 initscr();
 noecho();
 timeout(0);
 curs_set(0);
 cbreak();
 getmaxyx(stdscr, max_y, max_x);

 a.s.x=0;
 a.s.y=0;
 a.dx=XHEN;
 a.dy=YHEN;

 fill_box(a, c);
 refresh();

 while(1){
   clear();
   key=getch();

   if(key=='w'){
     a.s.y--;
   }
   if(key=='s'){
     a.s.y++;
   }
   if(key=='d'){
     a.s.x++;
   }
   if(key=='a'){
     a.s.x--;
   }
   if(key=='q'){
     break;
   }
   if(a.s.y<0 || (a.s.y+YHEN-1)==max_y || a.s.x<0 || (a.s.x+XHEN-1)==max_x){
    break;
  }

   fill_box(a, c);
   refresh();
   usleep(WAIT);
}

endwin();

return 0;
}

int draw_point( Point a, char c )
{
   int status;
   int max_y, max_x;

  getmaxyx( stdscr, max_y, max_x);
  if( (a.y>=0)&&(a.y<max_y)&&(a.x>=0)&&(a.x<max_x) ){
     status=0;
     move(a.y, a.x);  // 移動（縦、横の順）
     addch( c );      // １文字書く
   }else {
     status=1;
   }
   return status;
 }

int fill_box( Box a, char c)
{
  int status=0;
  int i,j;
  Point p;

  for( i=0; i<a.dx; i++){
    for( j=0; j<a.dy; j++){
      p.x=a.s.x+i;
      p.y=a.s.y+j;
      if( (status=draw_point(p, c))==1) break;
    }
    if(status==1) break;
  }
  return status;
}
