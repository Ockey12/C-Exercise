#include<stdio.h>

int main(void)
{
  int *p1;
  int p3=0;
  p1 = &p3;
  *p1 = 1;
  printf("%d\n", p3);

  return 0;
 
}
