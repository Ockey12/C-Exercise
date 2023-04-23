#include<stdio.h>

void swap_double( double *x, double *y );

int main(void)
{
  double a, b;

  printf("a:"); scanf("%lf", &a);
  printf("b:"); scanf("%lf", &b);

  swap_double( &a, &b );

  printf("a:%f\nb:%f\n", a, b);


  return 0;

}

void swap_double( double *x, double *y )
{
  double box;

  box = *x;
  *x = *y;
  *y = box;

}
