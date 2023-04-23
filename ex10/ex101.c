#include <stdio.h> 

int main()
{
  FILE *fp;
  int i;

  for(i=0;i<10;i++){
    fp = fopen("test01.dat", "w"); // "a"と"w"の違いは？
    fprintf( fp, "Hello World\n" );
    fclose( fp );
  }

  return 0;

}
