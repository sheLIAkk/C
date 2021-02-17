#include <stdio.h>

// fahr=0, 20, ..., 300に対して、摂氏-華氏対応表を印字する
main()
{
  float fahr, celsius; // 浮動小数点数って言ってるらしい
  int lower, upper, step; // 整数って言ってるらしい

  lower = 0; // 温度表の下限
  upper = 300; // 上限
  step = 20; // きざみ

  fahr = lower;
  printf("celsius - fahr\n");
  while (fahr <= upper) {
    // celsius = 5 * (fahr-32) / 9;  intの場合、小数部が計算で切り捨てられるのでこの順番らしい
    celsius = (5.0/9.0) * (fahr-32.0);
    //printf("%d\t%d\n", fahr, celsius); // %dは整数の引数なので、"fahr\t celsius\n"
    //printf("%3d %6d\n", fahr, celsius); // %3d...幅3桁のフィールドに右詰め
    printf("%3.0f %6.1f\n", fahr, celsius); // %6.1f...浮動小数点数として、少なくとも6文字幅で、小数点の後は1桁
    fahr = fahr + step;
  }
}