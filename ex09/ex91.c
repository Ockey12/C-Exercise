#include<stdio.h>
#include<math.h>

#define VERTEX 5//頂点の数

struct POINT{
  char name[10];
  double x;
  double y;
};

double length( double ax, double ay, double bx, double by );//2点間の距離を求める関数

int main(void)
{
  int count;
  struct POINT p[VERTEX];

  for( count=0; count<VERTEX; count++){
    printf("点%dの名前を入力してください:", count+1); scanf("%s", p[count].name);
    printf("点%sのxy座標を入力してください。\n", p[count].name);
    printf("x:"); scanf("%lf", &p[count].x);
    printf("y:"); scanf("%lf", &p[count].y);
  }

  for( count=1; count<VERTEX; count++){
    printf("%sと%sの距離は%fです。\n", p[0].name, p[count].name, length(p[0].x, p[0].y, p[count].x, p[count].y));
  }
      
  return 0;
}

double length( double ax, double ay, double bx, double by )
{
  double l;

  l = sqrt( (bx-ax)*(bx-ax) + (by-ay)*(by-ay) );

  return l;
}

