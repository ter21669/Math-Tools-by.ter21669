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
  char ans;
  
  printf("連立方程式ツール(二元一次) : 連立方程式の解を算出します - VER 1.0.1\n\n");

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

  if (a == 0) {
    if (x1 > 1 || x1 < -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", x1, y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
    }
    else if (x1 == 1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
    }
    else if (x1 == 0) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
    }
    else if (x1 == -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, x2, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", t1, y2, t2, ikaix, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, t2, ikaix, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d になります。\n\n", y1, t1, y2, t2, ikaix, ikaiy);
          }
        }
      }
    }
  }
  else if (a == 1) {
    if (x1 > 1 || x1 < -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
    else if (x1 == 1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
    else if (x1 == 0) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
    else if (x1 == -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, t2, ikaix, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d, y = %d/%d になります。\n\n", y1, t1, y2, t2, ikaix, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
  }
  else if (a == 2) {
    if (x1 > 1 || x1 < -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
    }
    if (x1 == 1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
    }
    if (x1 == 0) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
    }
    if (x1 == -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, ikaiy);
          }
        }
      }
    }
  }
  if (a == 3) {
    if (x1 > 1 || x1 < -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dx+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ %dx+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ %dx=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ %dx-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dx%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dx%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dx%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dx%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dx%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", x1, y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
    if (x1 == 1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
    if (x1 == 0) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ %dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ %dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ %dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ %dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ %dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
    if (x1 == -1) {
      if (x2 > 1 || x2 < -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dx+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ %dx+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ %dx=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ %dx-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dx%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, x2, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == 0) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ %dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
      else if (x2 == -1) {
        if (y1 > 1) {
          if (y2 > 1) {
            printf("{ -x+%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 1) {
          if (y2 > 1) {
            printf("{ -x+y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x+y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x+y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x+y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x+y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == 0) {
          if (y2 > 1) {
            printf("{ -x=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 == -1) {
          if (y2 > 1) {
            printf("{ -x-y=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x-y=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x-y=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x-y=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x-y=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
        else if (y1 < -1) {
          if (y2 > 1) {
            printf("{ -x%dy=%d\n{ -x+%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 1) {
            printf("{ -x%dy=%d\n{ -x+y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == 0) {
            printf("{ -x%dy=%d\n{ -x=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 == -1) {
            printf("{ -x%dy=%d\n{ -x-y=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
          else if (y2 < -1) {
            printf("{ -x%dy=%d\n{ -x%dy=%d\n上記の連立方程式の解は、x = %d/%d, y = %d/%d になります。\n\n", y1, t1, y2, t2, xx1 / resx, xx2 / resx, yy1 / resy, yy2 / resy);
          }
        }
      }
    }
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