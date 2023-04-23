#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20//じゃんけんの最大繰り返し回数

int player();
int enemy();
int judge(int p, int e);

int main()
{
  char hand[][20]={"グー","チョキ","パー"};
  char result[][20] ={"負け", "あいこ","勝ち"};
  int c, count=0;
  int v=0;//勝った回数
  int p, e, l;

  srand( (unsigned)time(NULL) ); //乱数の準備
  printf("0:%s、1:%s、2:%s で数値を入力してください.\n", hand[0], hand[1], hand[2]);

  //繰り返し - プレイヤーが5回勝つか、じゃんけんが20回になるまで繰り返す
  //繰り返しの中でじゃんけんを何回したか、何回勝ったかを数えておく
  for(c=0; c<MAX; c++){
    p=player(); //関数 player でキーボード入力した値(手)を受け取る
    e=enemy(); //関数 enemy から相手の手を受け取る
    l=judge(p, e);//関数 judge で勝敗を判別し、戻り値で勝敗の値を受け取る
    
    count++;
    if(l==2){
      v++;
    }

   
    printf("%d回目 , player:%s , enemy:%s , judge:%s\n", c+1, hand[p], hand[e], result[l]);

    if(v==5){
      break;
    }
   
  }

  printf("勝率=%f％", (double)v/count*100);
  
  return 0;
}

//player関数を作る
int player(){
  int a;
  
  printf("手を入力");
  scanf("%d", &a);
  if(a!=0 && a!=1 && a!=2){
    a=player();
  }
  
  return a;
}

//enemy関数 - このまま使う
int enemy()
{
  return rand()%3; // 0～2からランダムな値を返す
}  

//judge関数を作る - 引数：プレイヤーの手(p)と相手の手(e)、戻り値：勝敗(負け:0,あいこ:1,勝ち:2)
int judge(int p, int e)
{
  int a;
  
  if(p==0){
    if(e==0){
      a=1;
    }else if(e==1){
      a=2;
    }else{
      a=0;
    }
  }

  if(p==1){
    if(e==0){
      a=0;
    }else if(e==1){
      a=1;
    }else{
      a=2;
    }
  }

  if(p==2){
    if(e==0){
      a=2;
    }else if(e==1){
      a=0;
    }else{
      a=1;
    }
  }

  return a;
      
}
