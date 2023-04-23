#include<stdio.h>

/*入力した整数値が５で割り切れるか割り切れないかを表示*/

int main(void)
{
  int A;

  printf("整数を入力してください ：");
  scanf("%d", &A);
  
  if (A % 5)

    /*{}で囲む*/
    
    {puts("その数は５で割り切れません");
}else{
    puts("その数は５で割り切れます");
    }
  
  return 0;
}
