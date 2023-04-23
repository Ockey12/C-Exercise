#include<stdio.h>
#include<math.h>

#define N_TERM 5 //項数を示す

int factorial(int x);

double errorValue(double x, int n);

int main()
{
  int n;
  double x = M_PI/6.0; //M_PIはπが入った記号定数
  double er;
  int a;

  printf("sin(%.3f)=%e\n", x, sin(x));

  for(n = 0; n < N_TERM; n++){
    printf("n=%d    err=%e\n", n + 1, errorValue(x, n + 1));
  }

  return 0;
}

//再帰関数
int factorial(int x)
{
  if(x == 1){
    return 1;
  }else{
    return x * factorial(x - 1);
  }
}

double errorValue(double x, int n)
{
  double a, b, d;
  int k, c;
  double ap = 0/*近似値用*/, er/*誤差用*/;

  //マクローリン展開の計算
  for(k = 0; k < n; k++){
   a = pow(-1, k);
   b = pow(x, 2 * k + 1);
   c = factorial(2 * k + 1);
   d = a * b / c;
   ap = ap + d;
     }

  //誤差の計算
  er = fabs(sin(x) - ap);

  return er;
      
}
