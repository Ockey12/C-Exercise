//閏年を判定する

#include<stdio.h>
int main()
{
  int year;

  printf("西暦年を入力してください。\n");
  scanf("%d", &year);

  if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
    printf("%d年 閏年 \n", year);
  }else{
    printf("%d年 平年 \n", year);
  }

  return 0;
}
