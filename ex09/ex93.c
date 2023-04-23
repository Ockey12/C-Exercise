#include<stdio.h>
#include<math.h>
#include<stdlib.h>//絶対値を求めるabs()を使うため

#define VERTEX 2//頂点の数

typedef struct POINT{
  double x;
  double y;
} Point;

typedef struct LINE{
  Point p[2];
} Line;

void rotate_line( Line *a, double theta );

int main(void)
{
  Point a[VERTEX];
  Line l;
  int count;
  double de;

  printf("線分を作る2つの頂点の成分を入力してください。\n");

  for( count=0; count<VERTEX; count++){
    printf("頂点%d\n", count+1);
    printf("x:"); scanf("%lf", &l.p[count].x);
    printf("y:"); scanf("%lf", &l.p[count].y);
  }

  printf("何°回転させますか\n");
  scanf("%lf", &de);

  de = M_PI * de / 180;

  printf("\n回転前\n");
  for( count=0; count<VERTEX; count++){
    printf("頂点%d:(%f,%f)\n", count+1, l.p[count].x, l.p[count].y);
  }
  
  rotate_line( &l, de);

  printf("\n回転した結果\n");
  for( count=0; count<VERTEX; count++){
    printf("頂点%d:(%f,%f)\n", count+1, l.p[count].x, l.p[count].y);
  }

  return 0;
}

void rotate_line( Line *a, double theta )
{
  double apx, apy, aqx, aqy;
  int count;

  apx = a->p[0].x;
  apy = a->p[0].y;
  aqx = a->p[1].x;
  aqy = a->p[1].y;

  a->p[0].x = apx*cos(theta) - apy*sin(theta);
  a->p[0].y = apx*sin(theta) + apy*cos(theta);

  a->p[1].x = aqx*cos(theta) - aqy*sin(theta);
  a->p[1].y = aqx*sin(theta) + aqy*cos(theta);

  for( count=0; count<2; count++){//-0になるのを防ぐ
    if( abs(a->p[count].x)<=0.0000009){
      a->p[count].x=abs(a->p[count].x);
    }
  }

  for( count=0; count<2; count++){
    if( abs(a->p[count].y)<=0.0000009){
      a->p[count].y=abs(a->p[count].y);
    }
  }
  

}
  
