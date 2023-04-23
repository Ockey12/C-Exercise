#include<stdio.h>

void quad( double *x); 

int main( void )
{
  double a=1.0;

  printf("%f\n", a ); 
  printf("%p\n", &a); 

  quad( &a );
  printf("%f\n", a );

  return 0;
}

void quad( double *x )
{
  *x = (*x) * 4.0;
}
