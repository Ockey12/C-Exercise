#include<stdio.h>

int main()
{

  int n;

  printf("整数を入力してください");
  scanf("%d", &n);

  if(n % 2 == 0){ {
    printf("%dは２の倍数です\n", n);
     }
    if(n % 3 == 0){
      printf("%dは３の倍数です\n", n);
     }
    if(n % 5 == 0){
      printf("%dは５の倍数です\n", n);
     }
    if(n % 7 == 0){
      printf("%dは７の倍数です\n", n);
     }
    }

  else if(n % 3 == 0){ {
    printf("%dは３の倍数です\n", n);
    }
    if(n % 5 == 0){
      printf("%dは５の倍数です\n", n);
    }
    if(n % 7 == 0){
      printf("%dは７の倍数です\n", n);
    }
  }

  else if(n % 5 == 0){ {
      printf("%dは５の倍数です\n", n);
    }
    if(n % 7 == 0){
      printf("%dは７の倍数です\n", n);
    }
  }

  else if(n % 7 == 0){
    printf("%dは７の倍数です\n", n);
  }
  
  printf("おわり\n");

  return 0;
}
