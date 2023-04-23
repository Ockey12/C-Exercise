#include <stdio.h>

#define STUDENT 5

int main(void)
{
  int coun1, coun2, coun3;
  int point[STUDENT];
  int max, min, sum;

  puts("５人の点数を入力してください。");
  for (coun1 = 0; coun1 < STUDENT; coun1++) {
    printf("%d番:", coun1 + 1);
    scanf("%d", &point[coun1]);
    sum += point[coun1];
  }

  printf("\n");
  
  max = point[0];
  min = point[0];
  for (coun2 = 1; coun2 < 5; coun2++) {
    if(max < point[coun2]) {
      max = point[coun2];
    }

    if(min > point[coun2]) {
      min = point[coun2];
    }
  }

  puts("数学の成績");
  puts(" 出席番号   点数");

  for(coun3 = 0; coun3 < STUDENT; coun3++) {
    printf("%9d%7d\n", coun3 + 1, point[coun3]);
  }

  printf("\n");
  printf("最高点=%d\n", max);
  printf("最低点=%d\n", min);
  printf("平均点=%.2f\n", (double)sum / STUDENT);

  return 0;
}
  
