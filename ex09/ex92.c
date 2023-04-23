#include<stdio.h>
#include<math.h>

#define VERTEX 2//ベクトルの数

typedef struct VECT3{
  double x[3];
}Vect3;

double dot_prod( Vect3, Vect3 );

int main(void)
{
  Vect3 p[2];
  int count;

  for( count=0; count<VERTEX; count++){
    printf("ベクトル%dのxyz成分を入力してください。\n", count+1);
    printf("x:"); scanf("%lf", &p[count].x[0]);
    printf("y:"); scanf("%lf", &p[count].x[1]);
    printf("z:"); scanf("%lf", &p[count].x[2]);
  }

  printf("\n");
  
  for( count=0; count<VERTEX; count++){
    printf("ベクトル%d:(%f,%f,%f)\n",count+1, p[count].x[0], p[count].x[1], p[count].x[2]);
  }

  printf("内積:%f\n\n", dot_prod( p[0], p[1]));
  
  return 0;
}

double dot_prod( Vect3 a, Vect3 b )
{
  double ip;

  ip = a.x[0]*b.x[0] + a.x[1]*b.x[1] + a.x[2]*b.x[2];
  
  return ip;
  
}
