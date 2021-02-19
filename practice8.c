#include <stdio.h>
#define MAXLIME 1000  /* 入力行の最大長 */

int get_line(char line[], int max);
int stringdex(char source[], char searrchfor[]);

char pattern[] = "ould";

/* パターンにマッチするすべての行を探す */
int main () {
  char line[MAXLIME];
  int found = 0;

  while (get_line(line, MAXLIME) > 0)
    if (stringdex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    } else printf("ないよ");
  return found;
}

/* get_line:  sに行を入れ、長さを返す (practice5) */
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

/* stringdex: sにおけるtのindexを返す、どこにもなければ-1 */
int stringdex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') // 途中で死ぬとt[k] != '\0' なのでここに来ない
      return i;
  }
  return -1;
}