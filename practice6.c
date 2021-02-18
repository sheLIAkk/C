#include <stdio.h>
#define MAXLINE 1000 // 入力の最大

int detab(char s[], int lim);

/*タブをブランクで置き換える*/
// 置き換えた行を印字する
int main () {
  char line[MAXLINE];
  while (detab(line, MAXLINE) > 0) { // 行の長さが0より大きい
    printf("%s", line);
  }
  return 0;
}

// その行のタブをブランクに置き換える
int detab (char s[], int lim) {
  int c, i, n, j, t;      // iが文字数, tがタブストップ幅
  t = 4;
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n' && c!='\t'; ++i)
    s[i] = c;
  if (c == '\t') {
    n = t - (i % t);
    for (j=0; j<n; j++) {
      s[i] = ' ';
      i++;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
