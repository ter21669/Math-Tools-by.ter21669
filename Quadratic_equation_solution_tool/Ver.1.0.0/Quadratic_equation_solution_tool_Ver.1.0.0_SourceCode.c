#include <stdio.h>
#include <math.h>

int main(void) {

  int a, b, c, d, e;
  double kai1, kai2;
  char ans;
  
  printf("二次方程式ツール : 二次方程式を算出します。 - VER 1.0.0\n\n");
  
  while (1) {
  
  printf("3つの整数をそれぞれ入力して下さい。ただし、x^2の係数は0以外にしてください。\n");

  while (1) {
    printf("x^2の係数 : ");
    
    if (scanf("%d", &a) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }

    if (a == 0) {
      printf("Error 1 : 0以外の数値を入力してください。\n");
      while (getchar() != '\n');
    }
    else {
      break;
    }
  }

  while (1) {
    printf("xの係数 : ");

    if (scanf("%d", &b) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }
    break;
  }
  
  while (1) {
    printf("定数項 : ");

    if (scanf("%d", &c) != 1) {
      printf("Error 0 : その値は整数ではありません。\n");
      while (getchar() != '\n'); 
      continue;
    }
    break;
  }

  d = pow(b, 2) - 4 * a * c;

  if (d > 0) {
    kai1 = (-b + sqrt(d)) / (2 * a);
    kai2 = (-b - sqrt(d)) / (2 * a);
    e = 0;
  }
  if (d == 0) {
    kai1 = (-b + sqrt(d)) / (2 * a);
    e = 1;
  }
  if (d < 0) {
    e = 2;
  }
  
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %f と %f になります。\n", a, b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %f になります。\n", a, b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %f と %f になります。\n", a, b, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx の解は、 %f になります。\n", a, b, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%dx の解は、 実数解が存在しません。\n", a, b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %f と %f になります。\n", a, b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %f になります。\n", a, b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%dx%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %f と %f になります。\n", a, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x+%d の解は、 %f になります。\n", a, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+x+%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x の解は、 %f と %f になります。\n", a, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x の解は、 %f になります。\n", a, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+x の解は、 実数解が存在しません。\n", a);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %f と %f になります。\n", a, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x%d の解は、 %f になります。\n", a, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+x%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%d の解は、 %f と %f になります。\n", a, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%d の解は、 %f になります。\n", a, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2 の解は、 %f と %f になります。\n", a, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2 の解は、 %f になります。\n", a, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2 の解は、 実数解が存在しません。\n", a);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%d の解は、 %f と %f になります。\n", a, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%d の解は、 %f になります。\n", a, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %f と %f になります。\n", a, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x+%d の解は、 %f になります。\n", a, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2-x+%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x の解は、 %f と %f になります。\n", a, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x の解は、 %f になります。\n", a, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2-x の解は、 実数解が存在しません。\n", a);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %f と %f になります。\n", a, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x%d の解は、 %f になります。\n", a, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2-x%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %f と %f になります。\n", a, b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %f になります。\n", a, b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%dx+%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %f と %f になります。\n", a, b, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx の解は、 %f になります。\n", a, b, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%dx の解は、 実数解が存在しません。\n", a, b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %f と %f になります。\n", a, b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx%d の解は、 %f になります。\n", a, b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%dx%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx+%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx の解は、 %f と %f になります。\n", b, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx の解は、 %f になります。\n", b, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x+%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x+%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x の解は、 %f と %f になります。\n", kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x の解は、 %f になります。\n", kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2 の解は、 %f と %f になります。\n", kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2 の解は、 %f になります。\n", kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2 の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x+%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x+%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2-x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x の解は、 %f と %f になります。\n", kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x の解は、 %f になります。\n", kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2-x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2-x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx+%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx の解は、 %f と %f になります。\n", b, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx の解は、 %f になります。\n", b, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %f と %f になります。\n", b, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx の解は、 %f になります。\n", b, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x+%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x の解は、 %f と %f になります。\n", kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x の解は、 %f になります。\n", kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2 の解は、 %f と %f になります。\n", kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2 の解は、 %f になります。\n", kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2 の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x+%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2-x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x の解は、 %f と %f になります。\n", kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x の解は、 %f になります。\n", kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2-x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x%d の解は、 %f と %f になります。\n", c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x%d の解は、 %f になります。\n", c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2-x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx+%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx の解は、 %f と %f になります。\n", b, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx の解は、 %f になります。\n", b, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %f と %f になります。\n", b, c, kai1, kai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx%d の解は、 %f になります。\n", b, c, kai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }
  }

  while (1) {
    printf("\n引き続き二次方程式を算出しますか?(y/n) : ");
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