#include<stdio.h>

int keyInput()
{
  int a;
  printf("入力: ");
  scanf("%d", &a);

  return a;
}


int gcd(int n1, int n2)
{
  int a, b, rem;

  if (n1 >= n2) {
    a = n1;
    b = n2;
  } else {
    a = n2;
    b = n1;
  }
  
  while (rem != 0) {
    rem = a % b;
    if (rem != 0) {
      a = b;
      b = rem;
    } else {
      break;
    }
  }

  return b;
}


int main()
{
  int a, b, c;

  printf("２つの自然数の最大公約数を計算する\n");

   a = keyInput();
   b = keyInput();

   c = gcd(a, b);

   printf("%dと%dの最大公約数は%dです。\n",a, b, c);

  return 0;
}


