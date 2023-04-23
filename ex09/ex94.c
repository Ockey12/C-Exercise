#include<stdio.h>
#include<math.h>
//最も近い点が複数あっても対応出来るプログラム

#define VERTEX 5//頂点の数

typedef struct POINT{
  char name[10];
  double x;
  double y;
} Point;

double length( double ax, double ay, double bx, double by );//2点間の距離を求める関数

int main(void)
{
  Point p[VERTEX];
  int count;
  double l[VERTEX];
  double min;
  int s[VERTEX];
  int n, m, a;

  for( count=0; count<VERTEX; count++){//p[0]~p[4]
    printf("点%dの名前を入力してください:", count+1); scanf("%s", p[count].name);
    printf("点%sのxy座標を入力してください。\n", p[count].name);
    printf("x:"); scanf("%lf", &p[count].x);
    printf("y:"); scanf("%lf", &p[count].y);
  }

  for( count=1; count<VERTEX; count++){//l[1]~l[4]
    l[count] = length( p[0].x, p[0].y, p[count].x, p[count].y);
  }

printf("\n");

for( count=1; count<VERTEX; count++){
  printf("%sと%sの距離:%f\n", p[0].name, p[count].name, l[count]);
}

min=l[1];
for( count=2; count<VERTEX; count++){//p[0]との距離の最小値を求める
  if( min>l[count]){
    min=l[count];
      }
    }

n=0;
for( count=1; count<VERTEX; count++){//p[0]との距離が最小値と等しい点の番号をshort[]に入れる
  if( min==l[count]){
    s[n]=count;
    n++;
  }
}

printf("\n%sに最も近い点\n", p[0].name);

m=0;
s[n]=VERTEX;
while( s[m]!=VERTEX){
  a=s[m];
  printf("名前:%s\n", p[a].name);
  printf("%sとの距離:%f\n", p[a].name, l[a]);
  printf("xy座標:(%f, %f)\n\n", p[a].x, p[a].y);
  m++;
}

  return 0;
}

double length( double ax, double ay, double bx, double by )
{
  double l;

  l = sqrt( (bx-ax)*(bx-ax) + (by-ay)*(by-ay) );

  return l;
}
