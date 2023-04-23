#include<math.h>
#include<stdio.h>

int main()
{
  int ax, ay, bx, by;
  double l;

  printf("点Aの(x,y)を入力してください。\n");
  scanf("%d %d", &ax, &ay);

  printf("点Bの(x,y)を入力してください。\n");
  scanf("%d %d", &bx, &by);

  l = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));

  printf("点Aと点Bの距離は%fです。\n", l);
  return 0;
}
  
  
  
