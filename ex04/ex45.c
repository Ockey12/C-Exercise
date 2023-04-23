#include<stdio.h>

int main()
{
  int a;
  int m;//main
  int c;//cross
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
  printf(" 1|");

   for( a = 1; a < 82; a++ ) {
    m =  ( a + 8 ) % 9 + 1 ;
    c = ( a - 1 ) / 9 + 1;
    printf("%3d", m * ( c + 1 ) );
    if ( a % 9 == 0 ) {
      printf("\n");
      if ( a < 81 ) {
	printf("%2d|", a / 9 + 1 );
      }
    }
  }
   

  return 0;
}
