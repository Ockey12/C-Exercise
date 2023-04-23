#include <stdio.h>
#define STUDENT 5//記号定数 - 人数

typedef struct SEISEKI{
  char name[10];
  double average;
  int english;
  int math;
  char grade;
}Seiseki;

void calcGrade(Seiseki *a);

int main()
{
  FILE *fp;
  Seiseki s[STUDENT];
  char dummy1[10], dummy2[10], dummy3[10], dummy4[10];
  int c;
  char Name, Grade, Average, English, Math;
  

  //ファイル(seiseki.dat)を開く, ファイルがないときのエラー処理
  if( (fp = fopen("seiseki.dat", "r")) == NULL){
    printf("ファイルが存在しません\n");
  }else{
    for(c=0; c<STUDENT; c++){
      if(c==0){
	fscanf(fp, "%s %s %s %s", dummy1, dummy2, dummy3, dummy4);
      }else{
	fscanf(fp, "%s %lf %d %d", s[c].name, &s[c].average, &s[c].english, &s[c].math);
      }
    }
    fclose(fp);
  }

  for(c=0; c<STUDENT; c++){
    calcGrade(&s[c]);
  }

  //ファイル(output.dat)を開く
  //ファイルに書き込む
  //ファイルを閉じる

  
 fp = fopen("output.dat", "a");
 for(c=0; c<STUDENT; c++){
   if(c==0){
     fprintf(fp, "%s %s %s %s %s\n", &dummy1, &Grade, &dummy2, &dummy3, &dummy4);
   }else{
     fprintf(fp, "%s %s %f %d %d\n", s[c].name, &s[c].grade, s[c].average, s[c].english, s[c].math);
   }
 }
 fclose(fp);
 
  return 0;
}

//グレードを計算する関数を作る
void calcGrade(Seiseki *a){
  //平均点がグレードのどの範囲にあるかを調べて、そのグレードに対応した１文字を構造体のメンバgradeに代入する

  int c;
  double s;
  char D, C, B, A, S;

  for(c=0; c<STUDENT; c++){
    s = a->average;
    if(s < 60){
      a->grade = D;
    }else if(s >= 60 && s < 70){
      a->grade = C;
    }else if(s >= 70 && s < 80){
      a->grade = B;
    }else if(s >= 80 && s < 90){
      a->grade = A;
    }else{
      a->grade = s;
    }
  }
  
}

