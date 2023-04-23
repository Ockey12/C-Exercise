#include <stdio.h>
int main( void )
{
 int i=1;
 int c;
 double x=1.0;
 int j[5]={1,2,3,4,5};
 double y[5]={1.0,2.0,3.0,4.0,5.0};

 printf("address=%p  value=%d\n", &i, i );
 printf("address=%p  value=%f\n", &x, x );

 for(c = 0; c < 5; c++){
   printf("j[%d] address=%p\n", c, &j[c]);
 }

 printf("\n");
 
 for(c = 0; c < 5; c++){
   printf("y[%d] address=%p\n", c, &y[c]);
 }

  return 0;
}
