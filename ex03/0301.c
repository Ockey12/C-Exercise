#include<stdio.h>

/*入力した整数値が５で割り切れるか*/

int main(void)
{
  int A;

  printf("整数を入力してください : ");
  scanf("%d", &A);

  /*A%BはAをBで割った余り*/
  
  if (A % 5)
    puts("その数は５で割り切れません");

  return 0;
}
