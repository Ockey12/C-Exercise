/* w:上に移動,s:下に移動,d:右に移動,a:左に移動,q:終了
   b:画面端に当たると反射(デフォルト),v:画面端に当たると反対側に移動
   n:斜めに移動,m:斜め移動を解除(デフォルト)*/
#include <curses.h>
#include <unistd.h>
#define XHEN 15
#define YHEN 10
#define WAIT 40000

typedef struct POIN{
  int x;
  int y;
} Point;

typedef struct BOX{
  Point s;           // 左上の座標
  int   dx;          // ｘ方向の辺の長さ
  int   dy;          // ｙ方向の辺の長さ
} Box;

int draw_point( Point a, char c );

int fill_box(Box a, char c);

int main(void)
{
 Box a;
 char c;
 int max_x, max_y;
 char key;
 int move_x, move_y;
 int na=1;
 int command=0;

 c='W';

 initscr();
 noecho();
 timeout(0);
 curs_set(0);
 cbreak();
 getmaxyx(stdscr, max_y, max_x);

 a.s.x=max_x/2;
 a.s.y=max_y/2;
 a.dx=XHEN;
 a.dy=YHEN;

 fill_box(a, c);

 while(1){
   clear();
   key=getch();

   if(key=='w'){
     if(na==1){
       move_x=0;
     }
     move_y=-1;
   }
   if(key=='s'){
     if(na==1){
       move_x=0;
     }
     move_y=1;
   }
   if(key=='d'){
     if(na==1){
       move_y=0;
     }
     move_x=1;
   }
   if(key=='a'){
     if(na==1){
       move_y=0;
     }
     move_x=-1;
   }
   if(key=='q'){
     break;
   }
   if(key=='b'){
     command=0;
   }
   if(key=='v'){
     command=1;
   }
   if(key=='n'){
     na=0;
   }
   if(key=='m'){
     na=1;
   }

   switch(command){
     case 0://反射
       if(a.s.y==0){
        move_y=move_y*(-1);
       }
       if(a.s.x==0){
        move_x=move_x*(-1);
       }
       if((a.s.y+a.dy)==max_y){
        move_y=move_y*(-1);
       }
       if((a.s.x+a.dx)==max_x){
         move_x=move_x*(-1);
       }
         break;
    case 1://反対に戻る
      if(a.s.x<0){
        a.s.x=max_x-1-a.dx;
      }
      if(a.s.y<0){
        a.s.y=max_y-1-a.dy;
      }
      if((a.s.x+a.dx)==max_x){
        a.s.x=0;
      }
      if((a.s.y+a.dy)==max_y){
        a.s.y=0;
      }
   }

  a.s.x=a.s.x+move_x;
  a.s.y=a.s.y+move_y;

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
