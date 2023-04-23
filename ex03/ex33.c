#include<stdio.h>
#include<math.h>

int main()
{
  double s, t;
  int u;

     printf("初項、公比、項数を入力してください\n");
     printf("初項=");
     scanf("%lf", &s);

     printf("公比=");
     scanf("%lf", &t);

     printf("項数=");
     scanf("%d", &u);

     int count = 0, v;
     double sum;

     while(count < u){
     count = count + 1;
     v = pow(t,count-1);
     sum = s * v;

     printf("n=%d %f\n", count, sum);
  } 

  return 0;
}
