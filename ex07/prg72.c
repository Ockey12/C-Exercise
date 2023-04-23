#include<stdio.h>
int main()
{
  int i;
  char c;

  scanf("%c", &c); // 1文字入力し、文字型の変数 c にいれる.
  i = c; // char型からint型に暗黙の型変換が行われる.
  printf("Value of i = %x\n", i); // 文字コードが16進数で出力される.

  c = 0x62; //16進数で文字型に数字を入れる. 10進数だと, 98. 内部表現は01100010
  printf("c = %c\n", c); // 内部表現に対応した文字が表示される

  return 0;
}
