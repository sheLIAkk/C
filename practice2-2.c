#include <stdio.h>
// 2-1の改良

// magic numberを避けよう
#define   LOWER  0    /* 表の下限*/
#define   UPPER  300  /* 上限 */
#define   STEP   20   /* ステップサイズ */
main()
{
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}