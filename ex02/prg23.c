#include<stdio.h>

int main()
{

  int n;
  double x;

  printf("整数を入力してくださいお願いしますなんでもしますから\n");
  scanf("%d", &n);
  printf("入力した数自は %d です。\n", n);

  printf("浮動小数点数を入力してください\n");
  scanf( "%lf", &x );
  printf("入力した数自は %f です。\n", x);

  printf("整数と浮動小数点数を入力してください\n");
  scanf("%d %lf", &n, &x );
  printf("入力した整数は %d 浮動小数点数は %f です。\n", n, x);

  printf("整数を入力: "); scanf("%d", &n);
  printf("浮動小数点数を入力: "); scanf("%lf", &x);
  printf("入力した整数は %d 浮動小数点数は %f です。\n", n, x);

  return 0;
}

  
