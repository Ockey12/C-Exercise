#include <stdio.h>

#define STUDENT 8

int main(void)
{
  int coun1, star, coun2, coun3, coun4, coun5, coun6;//わかりにくいのでカウンタを区別
  int quo, X;
  int sum = 0;
  int point[STUDENT] = {90, 85, 60, 70, 100, 40, 75, 70};

  puts("数学の成績");
  puts(" 出席番号   点数");

  for(coun1 = 0; coun1 < STUDENT; coun1++) {
    printf("%9d%7d  ", coun1 + 1, point[coun1]);
    quo = point[coun1] / 10;
    for(star = 0; star < quo; star++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n\n");
  
  for(coun2 = 0; coun2 < STUDENT; coun2++) {
    sum += point[coun2];
  }
  printf("平均点=%.2f\n", (double)sum / STUDENT);

  printf("\n\n");
  
  puts("最高点");

  for(coun3 = 0; coun3 < STUDENT; coun3++) {
    for(coun4 = coun3 + 1; coun4 < STUDENT; coun4++) {
      if(point[coun3] < point[coun4]) {
	X = point[coun3];
	point[coun3] = point[coun4];
	point[coun4] = X;//小さいほうを後ろの番号へ
      }
    }
  }

  for(coun5 = 0; coun5 < STUDENT; coun5++) {
    printf("%6d\n", point[coun5]);
  }
  
  puts("最低点");

  printf("\n\n");

  puts("グレードの人数");

  int S = 0, A = 0, B = 0, C = 0, D = 0;
  for(coun6 = 0; coun6 < STUDENT; coun6++) {
    if(point[coun6] < 60) {
      D++;
    }
    if(60 <= point[coun6] && point[coun6] <= 69) {
      C++;
    }
    if(70 <= point[coun6] && point[coun6] <= 79) {
      B++;
    }
    if(80 <= point[coun6] && point[coun6] <= 89) {
      A++;
    }
    if(90 <= point[coun6] && point[coun6] <= 100) {
      S++;
    }
  }

  printf("S:%d人,", S);
  printf(" A:%d人,", A);
  printf(" B:%d人,", B);
  printf(" C:%d人,", C);
  printf(" D:%d人\n", D);
      
    return 0;
}
