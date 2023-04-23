#include<stdio.h>
#include<math.h>
int  main( void )
{
    int i;
    i = -3;
    printf("unsigned int: %u\n", i); //符号無し整数　%u

    printf("d:%d\n", i);
    printf("u:%u\n", i);
    printf("x:%x\n", i);

    printf("2の31乗:%f\n", pow(2,31));

    return 0;
}
