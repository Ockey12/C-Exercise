#include<stdio.h>

int main()
{
  double cm, m, mm;

  /*きーぼーど入力*/
  printf("長さをmmの単位で入力してください\n");
  scanf("%lf", &mm);

  /*計算*/
  cm = mm / 10.0;
  m = mm / 100.0;

  /*画面に表示*/
  printf("%f [mm] = %f [cm] = %f [m]\n", mm, cm, m );
  return 0;
}
