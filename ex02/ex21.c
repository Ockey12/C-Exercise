#include<stdio.h>

int main()
{
  int V, S, H, volume;

  printf("縦の長さをcmの単位で入力してください。\n");
  scanf("%d", &V);

  printf("横の長さをcmの単位で入力してください。\n");
  scanf("%d", &S);

  printf("高さをcmの単位で入力してください。\n");
  scanf("%d", &H);

  volume = V*S*H;

  printf("%d [cm^3] \n", volume);
  return 0;
}

  
  
