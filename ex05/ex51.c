#include <stdio.h>

int main(void)

{
  int n1, n2;
  int a, b;
  int rem;
  
  puts("２つの自然数を入力してください。");
  printf("自然数A:"); scanf("%d", &n1);
  printf("自然数B:"); scanf("%d", &n2);

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

  printf("最大公約数は%dです。\n", b);

  return 0;
}
