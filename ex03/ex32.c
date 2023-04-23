#include<stdio.h>

int main()
{
  double s, t;
  int u;

     printf("初項、公差、項数を入力してください\n");
     printf("初項=");
     scanf("%lf", &s);//%lf\nだと公差が表示されない

     printf("公差=");
     scanf("%lf", &t);

     printf("項数=");
     scanf("%d", &u);

     int count = 0;
     double sum;

     while(count < u){
     count = count + 1;
     sum = s + (count - 1) * t;

     printf("n=%d %f\n", count, sum);
  } 

  return 0;
}
  
