#include<stdio.h>

int main()
{
  int a, b, ab;
  int r;//列数
  int s;//"---"の数
  
  //列数を後から変更できるようrとおく
  printf("  |");
  for( r = 1; r < 10; r++ ) {
    printf("%3d", r);
  }
  printf("\n");

  //列数にあわせて自動で描くようにする
  for( s = 1; s < r + 1; s++ ) {
    printf("---");
  }
  printf("\n");

    for( a = 1; a < 10; a++ ) {
      printf("%2d|", a);
      for( b = 1; b < 10; b++ ) {
	ab = ( a + 1 ) * b;
	printf("%3d", ab);
	if ( ab == 30 ) {
	  break;
	}
      }
      printf("\n");
       if ( ab == 30 ) {
	break;
      }
    }
    return 0;
}
