#include<stdio.h>

#define INPUT_MAX 20

void max_min( int *array, int n, int *max, int *min );

double mean( int *array, int n );

double variance( int *array, int n );

int main(void)
{
  int num[INPUT_MAX];
  int a, n;
  int count = 0;
  int max = 0, min = 0;

  for (n = 0; n < INPUT_MAX; n++){
    num[n] = 0;
  }

  printf("20個までの数字を入力することができます。\n");
  printf("0が入力されると入力を終了します。\n");
  
  for (n = 0; n < INPUT_MAX; n++){
    scanf("%d", &a);
    num[n] = a;
    count++;
    if( num[n] == 0){
      count = count - 1;
      break;
    }
  }

  max_min( num, count, &max, &min);
  
  printf("最大値:%d\n", max);
  printf("最小値:%d\n", min);

  printf("平均値:%f\n", mean( num, count));

  printf("分散:%f\n", variance( num, count));
  
  
  return 0;
}

void max_min( int *array, int n, int *max, int *min )
{
  int i;

  *max = array[0];
  for ( i = 1; i < n; i++){
    if( *max < array[i] ){
      *max = array[i];
    }
  }

  *min = array[0];
  for ( i = 1; i < n; i++){
    if( *min > array[i] ){
      *min = array[i];
    }
  }

}

double mean( int *array, int n )
{
  int i;
  int sum = 0;
  double mean;

  for( i = 0; i < n; i++){
    sum += array[i];
  }

  mean = (double)sum / n;

  return mean;
}

double variance( int *array, int n )
{
  int i;
  int sum = 0;
  double mean;
  double hensa = 0;
  double nijo = 0, bunsan;

  for( i = 0; i < n; i++){
    sum += array[i];
  }

  mean = (double)sum / n;

  for( i = 0; i < n; i++){
    hensa = array[i] - mean;
    nijo += hensa * hensa;
  }

  bunsan = nijo / n;

  return bunsan;
}

