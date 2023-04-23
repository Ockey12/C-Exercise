#include<stdio.h>

int main(void)
{
  char str[] = "ABC123abc";
  int i = 0, n;
  
  printf("%s\n", str);

  while( str[i] != '\0'){
    i++;
  }
  //小文字を識別
  for( n = 0; n < i; n++){
    if( 'a' <= *(str + n) && *(str + n) <= 'z'){
      *(str + n) = *(str + n) -32;
    }
  }

  printf("%s\n", str);
  
  //大文字を識別
  for( n = 0; n < i; n++){
    if( 'A' <= str[n] && str[n] <= 'Z'){
      str[n] = str[n] + 32;
    }
  } 

  printf("%s\n", str);

  
  return 0;
}


