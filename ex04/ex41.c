#include<stdio.h>

int main()
{
  double h, g, bmi;
  
  printf("身長をm単位で入力してください:");
  scanf("%lf", &h);

  printf("体重をkg単位で入力してください:");
  scanf("%lf", &g);

  bmi = g / ( h * h );

  if ( bmi < 18.5 ) {
    printf("肥満度:低体重\nBMI:%.2f\n", bmi);
  } else if ( 18.5 <= bmi && bmi < 25 ) {
    printf("肥満度:普通体重\nBMI:%.2f\n", bmi);
  } else if ( 25 <= bmi && bmi < 30 ) {
    printf("肥満度:肥満1度\nBMI:%.2f\n", bmi);
  } else if ( 30 <= bmi && bmi < 35 ) {
    printf("肥満度:肥満2度\nBMI:%.2f\n", bmi);
  } else if ( 35 <= bmi && bmi < 40 ) {
    printf("肥満度:肥満3度\nBMI:%.2f\n", bmi);
  } else {
    printf("肥満度:肥満4度\nBMI:%.2f\n", bmi);
  }

  return 0;

}
