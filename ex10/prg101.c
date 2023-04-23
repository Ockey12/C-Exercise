/* ファイルに書き込む */
#include <stdio.h> 

int main()
{
  FILE *fp;

  fp = fopen("test01.dat", "w");
  fprintf( fp, "Hello World\n" );
  fclose( fp );

  return 0;

}
