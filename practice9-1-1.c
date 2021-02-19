#include <stdio.h>
#include <stdlib.h> //atof: 文字列を数字にする

#define MAXOP 100 // 被演算数、演算子の最大サイズ
#define NUMBER '0' // 数字があったという記号

int getop(char []); // 変数名入れなくてもいいやつ
void push(double);
double pop(void);
int sp = 0;

/* 逆ポーランド電卓 */
int main () {
  int type;
  double op2; // 右の被演算数を入れる
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int)pop() % (int)op2);
        else printf("error: zero divisor\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100 // valスタックの最大の深さ


double val[MAXVAL];

/* push: fを値スタックにプッシュする */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else
    printf("error: stack full, can't push %g\n", f); // %g: 実数を最適な形式で出力
}

/* pop: スタックから一番上の値をポップして返す */
double pop(void) {
  if (sp > 0) 
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: 次の演算子あるいは数値の被演算数をとってくる */
int getop(char s[]) { //mainの空の配列をあげる
  int i, c, d;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c;  // 数ではない
  if (c == '-' && !isdigit(d = getch())) { // 演算子の-
    ungetch(d);
    return c;
  }
  i = 0;
  if (c == '-') { // 負の数の-
    ungetch(d);
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (isdigit(c)) // 整数部を集める
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') // 小数部を集める
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // ungetch用の空きバッファ
int bufp = 0; // buf中の次の空き位置

/* (押し戻された可能性もある)1文字をとってくる */
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* 文字を入力に戻す */
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}