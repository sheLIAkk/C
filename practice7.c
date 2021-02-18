#include <stdio.h>
#define MAXLINE 1000 // 入力の最大

/* 入力行のn字文字目までにある最後の非ブランク文字のあとで折りたたむ */

int blank(char s[], int lim);
void fold(char to[], char from[], int t);

int main () {
  char line[MAXLINE];
  char folding[MAXLINE];
  int c;
  int num;
  while ((num = blank(line, MAXLINE)) > -2) {
    fold(folding, line, num);
    printf("%s", folding);
  }
  return 0;
}

// n以前の最後のブランクのindexを取得
int blank(char s[], int lim) {
  int c, i, t, n;  // t = 最後のタブor空白のindex
  t = -1;
  n = 15; // 折りたたむ位置
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
    s[i] = c;
    if ((c == '\t' || c == ' ') && i < n)
      t = i;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return t;
}

// n字文字目以降を"折りたたむ"（単語の途中で改行しない）
void fold(char to[], char from[], int t) {
  int i;

  i = 0;
  while (from[i] != '\0') {
    if (i == t) {
      to[i] = '\n';
    } else {
      to[i] = from[i];
    }
    i++;
  }
  to[i] = '\0';
}