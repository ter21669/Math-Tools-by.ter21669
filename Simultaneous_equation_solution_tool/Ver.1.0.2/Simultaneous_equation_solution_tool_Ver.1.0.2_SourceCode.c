#include <stdio.h>
#include <math.h>

int gcd(int gcda, int gcdb) {
  int temp;
  while (gcdb != 0) {
    temp = gcda % gcdb;
    gcda = gcdb;
    gcdb = temp;
  }
  return gcda;
}
int lcm(int lcma, int lcmb) {
  return (lcma / gcd(lcma, lcmb)) * lcmb;
}

int main (void) {

  int x1, y1, t1, x2, y2, t2, xx1, xx2, yy1, yy2, ikaix, ikaiy, resx, resy, a;
  double dxx1, dxx2, dxx, dyy1, dyy2, dyy, kaix, kaiy;
  char equ1[50], equ2[50], ans;
  
  printf("連立方程式ツール(二元一次) : 連立方程式の解を算出します - VER 1.0.2\n\n");

while (1) {
  printf("6つの整数をそれぞれ入力してください。Errorの詳細はReleaseの説明文を参照してください。\n\n");

  while (1) {
    printf("式1左辺 - xの係数 : ");

    if (scanf("%d", &x1) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }

    break;
  }
  while (1) {
    printf("式1左辺 - yの係数 : ");

    if (scanf("%d", &y1) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }

    if (y1 == 0 && x1 == 0) {
      printf("Error 1 : xの係数とyの係数をどちらも0にすることはできません。\n");
      while (getchar() != '\n');
    }
    else {
      break;
    }
  }
  while (1) {
    printf("式1右辺 - 定数項 : ");

    if (scanf("%d", &t1) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n');
      continue;
    }
    break;
  }

  printf("\n");
  while (1) {
    printf("式2左辺 - xの係数 : ");

    if (scanf("%d", &x2) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }

    if (x1 == 0 && x2 == 0) {
      printf("Error 3-1 : 2つの式でどちらもxの係数を0にすることはできません。\n");
      while (getchar() != '\n'); 
      continue;
    }
    break;
  }
  while (1) {
    printf("式2左辺 - yの係数 : ");

    if (scanf("%d", &y2) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }

    if (y1 == 0 && y2 == 0) {
      printf("Error 3-2 :  2つの式でどちらもyの係数を0にすることはできません。\n");
      while (getchar() != '\n'); 
      continue;
    }
    else if (y2 == 0 && x2 == 0) {
      printf("Error 1 : xの係数とyの係数をどちらも0にすることはできません。\n");
      while (getchar() != '\n');
    }
    else {
      break;
    }
  }
  while (1) {
    printf("式2右辺 - 定数項 : ");

    if (scanf("%d", &t2) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n');
      continue;
    }
    break;
  }

  printf("\n");
  xx1 = t1 * (lcm(y1, y2) / y1) - t2 * (lcm(y1, y2) / y2);
  xx2 = x1 * (lcm(y1, y2) / y1) - x2 * (lcm(y1, y2) / y2);
  yy1 = t1 * (lcm(x1, x2) / x1) - t2 * (lcm(x1, x2) / x2);
  yy2 = y1 * (lcm(x1, x2) / x1) - y2 * (lcm(x1, x2) / x2);
  dxx1 = t1 * (lcm(y1, y2) / y1) - t2 * (lcm(y1, y2) / y2);
  dxx2 = x1 * (lcm(y1, y2) / y1) - x2 * (lcm(y1, y2) / y2);
  dyy1 = t1 * (lcm(x1, x2) / x1) - t2 * (lcm(x1, x2) / x2);
  dyy2 = y1 * (lcm(x1, x2) / x1) - y2 * (lcm(x1, x2) / x2);
  kaix = xx1 / xx2;
  kaiy = yy1 / yy2;
  dxx = dxx1 / dxx2;
  dyy = dyy1 / dyy2;

  if (fmod(dxx, 1.0) == 0 && fmod(dyy, 1.0) == 0) {
    ikaix = kaix;
    ikaiy = kaiy;
    a = 0;
  }
  else if (fmod(dxx, 1.0) == 0 && fmod(dyy, 1.0) != 0) {
    resy = gcd(yy1, yy2);
    ikaix = kaix;
    a = 1;
  }
  else if (fmod(dyy, 1.0) == 0 && fmod(dxx, 1.0) != 0) {
    resx = gcd(xx1, xx2);
    ikaiy = kaiy;
    a = 2;
  }
  else {
    resx = gcd(xx1, xx2);
    resy = gcd(yy1, yy2);
    a = 3;
  }

  if (x1 > 1 || x1 < -1) {
    if (y1 > 1 || y1 < -1) {
      sprintf(equ1, "%dx%+dy=%d", x1, y1, t1);
    }
    else if (y1 == 1) {
      sprintf(equ1, "%dx+y=%d", x1, t1);
    }
    else if (y1 == 0) {
      sprintf(equ1, "%dx=%d", x1, t1);
    }
    else if (y1 == -1) {
      sprintf(equ1, "%dx-y=%d", x1, t1);
    }
  }
  else if (x1 == 1) {
    if (y1 > 1 || y1 < -1) {
      sprintf(equ1, "x%+dy=%d", y1, t1);
    }
    else if (y1 == 1) {
      sprintf(equ1, "x+y=%d", t1);
    }
    else if (y1 == 0) {
      sprintf(equ1, "x=%d", t1);
    }
    else if (y1 == -1) {
      sprintf(equ1, "x-y=%d", t1);
    }
  }
  else if (x1 == 0) {
    if (y1 > 1 || y1 < -1) {
      sprintf(equ1, "%+dy=%d", y1, t1);
    }
    else if (y1 == 1) {
      sprintf(equ1, "y=%d", t1);
    }
    else if (y1 == -1) {
      sprintf(equ1, "-y=%d", t1);
    }
  }
  else if (x1 == -1) {
    if (y1 > 1 || y1 < -1) {
      sprintf(equ1, "-x%+dy=%d", y1, t1);
    }
    else if (y1 == 1) {
      sprintf(equ1, "-x+y=%d", t1);
    }
    else if (y1 == 0) {
      sprintf(equ1, "-x=%d", t1);
    }
    else if (y1 == -1) {
      sprintf(equ1, "-x-y=%d", t1);
    }
  }

  if (x2 > 1 || x2 < -1) {
    if (y2 > 1 || y2 < -1) {
      sprintf(equ2, "%dx%+dy=%d", x2, y2, t2);
    }
    else if (y2 == 1) {
      sprintf(equ2, "%dx+y=%d", x2, t2);
    }
    else if (y2 == 0) {
      sprintf(equ2, "%dx=%d", x2, t2);
    }
    else if (y2 == -1) {
      sprintf(equ2, "%dx-y=%d", x2, t2);
    }
  }
  else if (x2 == 1) {
    if (y2 > 1 || y2 < -1) {
      sprintf(equ2, "x%+dy=%d", y2, t2);
    }
    else if (y2 == 1) {
      sprintf(equ2, "x+y=%d", t2);
    }
    else if (y2 == 0) {
      sprintf(equ2, "x=%d", t2);
    }
    else if (y2 == -1) {
      sprintf(equ2, "x-y=%d", t2);
    }
  }
  else if (x2 == 0) {
    if (y2 > 1 || y2 < -1) {
      sprintf(equ2, "%+dy=%d", y2, t2);
    }
    else if (y2 == 1) {
      sprintf(equ2, "y=%d", t2);
    }
    else if (y2 == -1) {
      sprintf(equ2, "-y=%d", t2);
    }
  }
  else if (x2 == -1) {
    if (y2 > 1 || y2 < -1) {
      sprintf(equ2, "-x%+dy=%d", y2, t2);
    }
    else if (y2 == 1) {
      sprintf(equ2, "-x+y=%d", t2);
    }
    else if (y2 == 0) {
      sprintf(equ2, "-x=%d", t2);
    }
    else if (y2 == -1) {
      sprintf(equ2, "-x-y=%d", t2);
    }
  }

  if (a == 0) {
    printf("{ %s\n{ %s\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", equ1, equ2, ikaix, ikaiy);
  }
  else if (a == 1) {
    printf("{ %s\n{ %s\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", equ1, equ2, ikaix, yy1 / resy, yy2 / resy);
  }
  else if (a == 2) {
    printf("{ %s\n{ %s\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", equ1, equ2, xx1 / resx, xx2 / resx, ikaiy);
  }
  else if (a == 3) {
    printf("{ %s\n{ %s\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", equ1, equ2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
  }

  while (1) {
    printf("引き続き連立方程式の解を算出しますか?(y/n) : ");
    if (scanf(" %c", &ans) != 1) {
      printf("Error 2 : yもしくはnを入力してください。");
      while (getchar() != '\n'); 
      continue;
    }

    while (getchar() != '\n');

    if (ans == 'y') {
      printf("操作を繰り返します。\n\n");
      break;
    }
    else if (ans == 'n') {
      printf("操作を終了します。\n");
      return 0;
    }
    else {
      printf("Error 2 : yもしくはnを入力してください。");
    }
  }
}

  return 0;
}