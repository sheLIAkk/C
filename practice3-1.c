#include <stdio.h>
main(){
  int c;

  c = getchar(); // 入力を取ってくる
  while (c != EOF) { // EOF = end of file
    putchar(c); // 出力する
    c = getchar();
  }
}