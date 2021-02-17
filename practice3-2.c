#include <stdio.h>
// 文字数カウント
int main(){
  long nc; // 長い整数

  nc = 0;
  while (getchar() != EOF){ // getcharは1文字ずつ持ってきてるらしいね
    ++nc;
  }
  printf("%ld\n", nc); // ctrl + D でEOF入力（linux）

  /* 別パターン
  double nc;
  for (nc = 0; getchar() != EOF; ++nc;)
    ;
  printf("%.0f\n", nc;)
  */
}