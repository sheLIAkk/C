#include <stdio.h>
#define MAXLINE 1000 /* 入力行の最大長 */

int get_line(char line[], int maxline); // getline()だとライブラリと衝突した
void copy(char to[], char from[]);

/* 最も長い入力行を印字する */
int main () {
  int len;  // 現在行の長さ
  int max;  // いままで出てきた最大長
  char line[MAXLINE]; // 現在の入力行
  char longest[MAXLINE]; // 格納されている最長行

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)  // 行があった
    printf("%s", longest);
  return 0;
}

/* get_line:  sに行を入れ、長さを返す */
int get_line(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: fromをtoにコピー；toは十分大きいと仮定 */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
