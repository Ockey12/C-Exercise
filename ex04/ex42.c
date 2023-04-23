#include <stdio.h>
int main()
{
  int count_return = 0;
  int mojisuu = 0;
  int gyo;

  while(1){
    gyo = getchar();
    if ( gyo == EOF ){
      break;
    }
    if ( gyo != EOF && gyo != '\n'){
      ++mojisuu;
    }
    if ( gyo == '\n' ){
      ++count_return;
      ++mojisuu;
    }
  }
  
  printf("%d文字、%d行ありました。\n", mojisuu, count_return );

  return 0;
}
