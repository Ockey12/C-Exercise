#include<stdio.h>

int str_num( char *str, int *big, int *small, int *num );

int main(void)
{
  char str[] = "2019ProgrammingEXERCISE2";
  int i = 0;
  int big, small, num;
  
  printf("%s\n", str);
   
  printf("文字列の長さ:%d\n",  str_num( str, &big, &small, &num));
  printf("大文字の数:%d\n", big);
  printf("小文字の数:%d\n", small);
  printf("数字の数:%d\n", num);
 
  return 0;
}

int str_num( char *str, int *big, int *small, int *num )
{
  int i = 0;
  int b = 0, s = 0, n = 0;
  
   while( str[i] != '\0'){
    i++;
  }
    
  //大文字を識別
  for( n = 0; n < i; n++){
    if( 'A' <= str[n] && str[n] <= 'Z'){
      b++;
    }
  }
  
     //小文字を識別
  for( n = 0; n < i; n++){
    if( 'a' <= str[n] && str[n] <= 'z'){
      s++; 
    }
  }

  n = i - ( b + s);

  *big = b;
  *small = s;
  *num = n;

  return i;
}
