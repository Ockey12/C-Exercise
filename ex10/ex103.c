#include<stdio.h>
#define MAX 40

typedef struct SEISEKI{ 
  int id;     /* 出席番号 */ 
  int math;   /* 数学の点 */ 
  int eng;    /* 英語の点 */
  int total;  /* 合計点 */
}Seiseki;

int main(void)
{
  FILE *fp;
  Seiseki s[MAX];
  int count=0;
  int stu;
  int maxe, maxm, maxt;

  if( (fp = fopen("seiseki10.dat", "r")) == NULL){
    printf("ファイルが存在しません\n");
  }else{
    while( fscanf( fp, "%d %d %d", &stu, &s[count].eng, &s[count].math) != EOF){
      s[count].total = s[count].math + s[count].eng;
      count++;
    }
    fclose(fp);
  }

  maxm = s[0].math;
  maxe = s[0].eng;
  maxt = s[0].total;
  
  for( count=1; count<stu; count++){
    if( maxe < s[count].eng){
      maxe = s[count].eng;
    }
    if( maxm < s[count].math){
      maxm = s[count].math;
    }
    if( maxt < s[count].total){
      maxt = s[count].total;
    }
  }

  fp = fopen("output.dat", "w");
  fprintf( fp, "学生数:%d\n英語の最高点:%d\n数学の最高点:%d\n合計の最高点:%d\n",
	   stu, maxe, maxm, maxt);
  fclose(fp);

  return 0;
}
