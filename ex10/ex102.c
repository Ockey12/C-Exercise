#include<stdio.h>
#define NDATA 5//生徒の数
#define SUB 2//科目の数

typedef struct SEISEKI{
  char name[20];     /* 名前 */
  int math;          /* 数学の点 */
  int eng;           /* 英語の点 */
  int total;         /* 合計点 */
  double ave;        /* 平均点 */
}Seiseki; 

int main(void)
{
  FILE *fp;
  Seiseki s[NDATA];
  int count;

  fp = fopen("seiseki03.dat", "r");
  for( count=0; count<NDATA; count++){
    fscanf( fp, "%s %d %d", s[count].name, &s[count].math, &s[count].eng);
  }
  fclose(fp);

  for( count=0; count<NDATA; count++){
    s[count].total = s[count].math + s[count].eng;
    s[count].ave = s[count].total / SUB;
  }
  
  fp = fopen("seiseki04.dat", "a");
  for( count=0; count<NDATA; count++){
    fprintf( fp, "%s %d %d %d %f \n",
	     s[count].name, s[count].math, s[count].eng, s[count].total, s[count].ave);
  }
  fclose(fp);

  return 0;
}
