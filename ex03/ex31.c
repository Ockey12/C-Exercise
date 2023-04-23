#include<stdio.h>

int main()
{
  int A, B;

  printf("整数を２つ入力してください\n");
  scanf("%d%d", &A, &B);

  if (A > B){
    printf("小さいほうは  %d 大きいほうは  %d です。\n", B, A);
  }

  else if (A < B){
    printf("小さいほうは  %d 大きいほうは  %d です。\n", A, B);
  }

  else if (A == B){
    printf("２つの数は等しいです。\n");
  }

  return 0;
}
