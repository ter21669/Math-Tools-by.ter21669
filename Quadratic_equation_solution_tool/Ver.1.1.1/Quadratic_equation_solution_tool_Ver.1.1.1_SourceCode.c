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

int main(void) {

  int a, b, c, d, e, f, ikai1, ikai2, sqrta, sqrtb, result1, result2;
  double kai1, kai2;
  char ans;
  
  printf("二次方程式ツール : 二次方程式の解を算出します - VER 1.1.1\n\n");
  
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

    if (fmod(kai1, 1.0) == 0 && fmod(kai2, 1.0) == 0) {
      ikai1 = kai1;
      ikai2 = kai2;
      f = 0;
    }
    else {
      sqrta = 1;
      sqrtb = d;

      for (int i = 2; i * i <= sqrtb; i++) {
        while (sqrtb % (i * i) == 0) {
            sqrta *= i;
            sqrtb /= (i * i);
        }
      }
      
      if (sqrta == 1) {
        if (sqrtb == 1) {
          result1 = gcd(-b + sqrt(d), 2 * a);
          result2 = gcd(-b - sqrt(d), 2 * a);
          f = 7;
        }
        else {
          result1 = 1;
          f = 1;
        }
      }
      else if (fmod(sqrt(d), 1.0) == 0) {
        if (fmod(kai1, 1.0) == 0 && fmod(sqrt(d), 1.0) == 0) {
          ikai1 = kai1;
          result1 = gcd(-b - sqrt(d), 2 * a);
          f = 5;
        }
        else if (fmod(kai2, 1.0) == 0 && fmod(sqrt(d), 1.0) == 0) {
          ikai2 = kai2;
          result2 = gcd(-b + sqrt(d), 2 * a);
          f = 6;
        }
        else {
          result1 = gcd(-b + sqrt(d), 2 * a);
          result2 = gcd(-b - sqrt(d), 2 * a);
          f = 7;
        }
      }
      else {
        result1 = gcd(gcd(2 * a, -b), sqrta);

        if (result1 == sqrta && sqrta != 2 * a) {
          f = 1;
        }
        else if (result1 == 2 * a && sqrta != 2 * a) {
          f = 2;
        }
        else if (sqrta == 2 * a && result1 == sqrta) {
          f = 3;
        }
        else {
          f = 4;
        }
      }
    }
  }

  if (d == 0) {
    kai1 = (-b + sqrt(d)) / (2 * a);
    e = 1;

    if (fmod(kai1, 1.0) == 0) {
      ikai1 = kai1;
      f = 0;
    }
    else {
      result1 = gcd(2 * a, -b);
      f = 1;
    }
  }

  if (d < 0) {
    e = 2;
    f = 0;
  }
  
if (f == 0) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d と %d になります。\n", a, b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d になります。\n", a, b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %d と %d になります。\n", a, b, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx の解は、 %d になります。\n", a, b, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%dx の解は、 実数解が存在しません。\n", a, b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d と %d になります。\n", a, b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d になります。\n", a, b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%dx%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d と %d になります。\n", a, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d になります。\n", a, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+x+%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x の解は、 %d と %d になります。\n", a, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x の解は、 %d になります。\n", a, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+x の解は、 実数解が存在しません。\n", a);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %d と %d になります。\n", a, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x%d の解は、 %d になります。\n", a, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+x%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%d の解は、 %d と %d になります。\n", a, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%d の解は、 %d になります。\n", a, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2+%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2 の解は、 %d と %d になります。\n", a, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2 の解は、 %d になります。\n", a, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2 の解は、 実数解が存在しません。\n", a);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%d の解は、 %d と %d になります。\n", a, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%d の解は、 %d になります。\n", a, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d と %d になります。\n", a, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d になります。\n", a, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2-x+%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x の解は、 %d と %d になります。\n", a, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x の解は、 %d になります。\n", a, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2-x の解は、 実数解が存在しません。\n", a);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %d と %d になります。\n", a, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x%d の解は、 %d になります。\n", a, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2-x%d の解は、 実数解が存在しません。\n", a, c);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d と %d になります。\n", a, b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d になります。\n", a, b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%dx+%d の解は、 実数解が存在しません。\n", a, b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %d と %d になります。\n", a, b, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx の解は、 %d になります。\n", a, b, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 %dx^2%dx の解は、 実数解が存在しません。\n", a, b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d と %d になります。\n", a, b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d になります。\n", a, b, c, ikai1);
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
          printf("二次方程式 x^2+%dx+%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx の解は、 %d と %d になります。\n", b, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx の解は、 %d になります。\n", b, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x+%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x+%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x の解は、 %d と %d になります。\n", ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x の解は、 %d になります。\n", ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2 の解は、 %d と %d になります。\n", ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2 の解は、 %d になります。\n", ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2 の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x+%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x+%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2-x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x の解は、 %d と %d になります。\n", ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x の解は、 %d になります。\n", ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2-x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2-x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx+%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx の解は、 %d と %d になります。\n", b, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx の解は、 %d になります。\n", b, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 x^2%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx%d の解は、 %d になります。\n", b, c, ikai1);
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
          printf("二次方程式 -x^2+%dx+%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %d と %d になります。\n", b, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx の解は、 %d になります。\n", b, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x+%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x の解は、 %d と %d になります。\n", ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x の解は、 %d になります。\n", ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2 の解は、 %d と %d になります。\n", ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2 の解は、 %d になります。\n", ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2 の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x+%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2-x+%d の解は、 実数解が存在しません。\n", c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x の解は、 %d と %d になります。\n", ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x の解は、 %d になります。\n", ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2-x の解は、 実数解が存在しません。\n");
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x%d の解は、 %d と %d になります。\n", c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x%d の解は、 %d になります。\n", c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2-x%d の解は、 実数解が存在しません。\n", c);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%dx+%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx の解は、 %d と %d になります。\n", b, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx の解は、 %d になります。\n", b, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%dx の解は、 実数解が存在しません。\n", b);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %d と %d になります。\n", b, c, ikai1, ikai2);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx%d の解は、 %d になります。\n", b, c, ikai1);
        }
        if (e == 2) {
          printf("二次方程式 -x^2%dx%d の解は、 実数解が存在しません。\n", b, c);
        }
      }
    }
  }
}

if (f == 1) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d/%d になります。\n", a, b, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, b, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx の解は、 %d/%d になります。\n", a, b, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d/%d になります。\n", a, b, c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d/%d になります。\n", a, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x の解は、 %d/%d になります。\n", a, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+x%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+x%d の解は、 %d/%d になります。\n", a, c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2+%d の解は、 √%d/%d と -√%d/%d になります。\n", a, c, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2+%d の解は、 %d/%d になります。\n", a, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2 の解は、 √%d/%d と -√%d/%d になります。\n", a, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2 の解は、 %d/%d になります。\n", a, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%d の解は、 √%d/%d と -√%d/%d になります。\n", a, c, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%d の解は、 %d/%d になります。\n", a, c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d/%d になります。\n", a, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x の解は、 %d/%d になります。\n", a, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2-x%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2-x%d の解は、 %d/%d になります。\n", a, c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d/%d になります。\n", a, b, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, b, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx の解は、 %d/%d になります。\n", a, b, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", a, b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d/%d になります。\n", a, b, c, -b / result1, 2 * a / result1);
        }
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx の解は、 %d/%d になります。\n", b, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%dx%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%dx%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x+%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x の解は、 %d/%d になります。\n", -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2+x%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+x%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2+%d の解は、 √%d/%d と -√%d/%d になります。\n", c, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2+%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2 の解は、 √%d/%d と -√%d/%d になります。\n", sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2 の解は、 %d/%d になります。\n", -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2%d の解は、 √%d/%d と -√%d/%d になります。\n", c, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x+%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x の解は、 %d/%d になります。\n", -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2-x%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2-x%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx+%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx の解は、 %d/%d になります。\n", b, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 x^2%dx%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 x^2%dx%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx の解は、 %d/%d になります。\n", b, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == 1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x+%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x の解は、 %d/%d になります。\n", -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+x%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+x%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == 0) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2+%d の解は、 √%d/%d と -√%d/%d になります。\n", c, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2+%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2 の解は、 √%d/%d と -√%d/%d になります。\n", sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2 の解は、 %d/%d になります。\n", -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%d の解は、 √%d/%d と -√%d/%d になります。\n", c, sqrtb, 2 * a / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b == -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x+%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x の解は、 %d/%d になります。\n", -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2-x%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2-x%d の解は、 %d/%d になります。\n", c, -b / result1, 2 * a / result1);
        }
      }
    }

    if (b < -1) {
      if (c > 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
      if (c == 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx の解は、 %d/%d になります。\n", b, -b / result1, 2 * a / result1);
        }
      }
      if (c < 0) {
        if (e == 0) {
          printf("二次方程式 -x^2%dx%d の解は、 (%d+√%d)/%d と (%d-√%d)/%d になります。\n", b, c, -b / result1, sqrtb, 2 * a / result1, -b / result1, sqrtb, 2 * a / result1);
        }
        if (e == 1) {
          printf("二次方程式 -x^2%dx%d の解は、 %d/%d になります。\n", b, c, -b / result1, 2 * a / result1);
        }
      }
    }
  }
}

if (f == 2) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, b, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+x の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%d の解は、 %d√%d と -%d√%d になります。\n", a, c, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2 の解は、 %d√%d と -%d√%d になります。\n", a, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%d の解は、 %d√%d と -%d√%d になります。\n", a, c, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2-x の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, b, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2+%dx の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 x^2+x+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2+x の解は、 %d+%d√%d と %d-%d√%d になります。\n", -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2+x%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 x^2+%d の解は、 %d√%d と -%d√%d になります。\n", c, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2 の解は、 %d√%d と -%d√%d になります。\n", sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2%d の解は、 %d√%d と -%d√%d になります。\n", c, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 x^2-x+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2-x の解は、 %d+%d√%d と %d-%d√%d になります。\n", -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2-x%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2%dx の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2%dx%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+x の解は、 %d+%d√%d と %d-%d√%d になります。\n", -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+x%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 -x^2+%d の解は、 %d√%d と -%d√%d になります。\n", c, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2 の解は、 %d√%d と -%d√%d になります。\n", sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%d の解は、 %d√%d と -%d√%d になります。\n", c, sqrta / result1, sqrtb, sqrta / result1, sqrtb);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2-x の解は、 %d+%d√%d と %d-%d√%d になります。\n", -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2-x%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2%dx の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %d+%d√%d と %d-%d√%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, -b / result1, sqrta / result1, sqrtb);
      }
    }
  }
}

if (f == 3) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d+√%d と %d-√%d になります。\n", a, b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %d+√%d と %d-√%d になります。\n", a, b, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d+√%d と %d-√%d になります。\n", a, b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d+√%d と %d-√%d になります。\n", a, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+x の解は、 %d+√%d と %d-√%d になります。\n", a, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %d+√%d と %d-√%d になります。\n", a, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%d の解は、 √%d と -√%d になります。\n", a, c, sqrtb, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2 の解は、 √%d と -√%d になります。\n", a, sqrtb, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%d の解は、 √%d と -√%d になります。\n", a, c, sqrtb, sqrtb);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d+√%d と %d-√%d になります。\n", a, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2-x の解は、 %d+√%d と %d-√%d になります。\n", a, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %d+√%d と %d-√%d になります。\n", a, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d+√%d と %d-√%d になります。\n", a, b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %d+√%d と %d-√%d になります。\n", a, b, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d+√%d と %d-√%d になります。\n", a, b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2+%dx の解は、 %d+√%d と %d-√%d になります。\n", b, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 x^2+x+%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2+x の解は、 %d+√%d と %d-√%d になります。\n", -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2+x%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 x^2+%d の解は、 √%d と -√%d になります。\n", c, sqrtb, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2 の解は、 √%d と -√%d になります。\n", sqrtb, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2%d の解は、 √%d と -√%d になります。\n", c, sqrtb, sqrtb);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 x^2-x+%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2-x の解は、 %d+√%d と %d-√%d になります。\n", -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2-x%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 x^2%dx の解は、 %d+√%d と %d-√%d になります。\n", b, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 x^2%dx%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %d+√%d と %d-√%d になります。\n", b, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+x の解は、 %d+√%d と %d-√%d になります。\n", -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+x%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 -x^2+%d の解は、 √%d と -√%d になります。\n", c, sqrtb, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2 の解は、 √%d と -√%d になります。\n", sqrtb, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%d の解は、 √%d と -√%d になります。\n", c, sqrtb, sqrtb);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2-x の解は、 %d+√%d と %d-√%d になります。\n", -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2-x%d の解は、 %d+√%d と %d-√%d になります。\n", c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c == 0) {
          printf("二次方程式 -x^2%dx の解は、 %d+√%d と %d-√%d になります。\n", b, -b / result1, sqrtb, -b / result1, sqrtb);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %d+√%d と %d-√%d になります。\n", b, c, -b / result1, sqrtb, -b / result1, sqrtb);
      }
    }
  }
}

if (f == 4) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, b, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+x の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+x%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%d の解は、 %d√%d/%d と -%d√%d/%d になります。\n", a, c, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2 の解は、 %d√%d/%d と -%d√%d/%d になります。\n", a, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%d の解は、 %d√%d/%d と -%d√%d/%d になります。\n", a, c, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2-x の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2-x%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2%dx の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, b, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", a, b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2+%dx の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2+%dx%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 x^2+x+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2+x の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2+x%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 x^2+%d の解は、 %d√%d/%d と -%d√%d/%d になります。\n", c, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2 の解は、 %d√%d/%d と -%d√%d/%d になります。\n", sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2%d の解は、 %d√%d/%d と -%d√%d/%d になります。\n", c, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 x^2-x+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2-x の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2-x%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 x^2%dx+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2%dx の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2%dx%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+%dx の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+x+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+x の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+x%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 -x^2+%d の解は、 %d√%d/%d と -%d√%d/%d になります。\n", c, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2 の解は、 %d√%d/%d と -%d√%d/%d になります。\n", sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%d の解は、 %d√%d/%d と -%d√%d/%d になります。\n", c, sqrta / result1, sqrtb, 2 * a / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 -x^2-x+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2-x の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2-x%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2%dx の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%dx%d の解は、 (%d+%d√%d)/%d と (%d-%d√%d)/%d になります。\n", b, c, -b / result1, sqrta / result1, sqrtb, 2 * a / result1, -b / result1, sqrta / result1, sqrtb, 2 * a / result1);
      }
    }
  }
}

if (f == 5) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %d と %d/%d になります。\n", a, b, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d と %d/%d になります。\n", a, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+x の解は、 %d と %d/%d になります。\n", a, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %d と %d/%d になります。\n", a, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%d の解は、 %d と %d/%d になります。\n", a, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2 の解は、 %d と %d/%d になります。\n", a, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%d の解は、 %d と %d/%d になります。\n", a, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d と %d/%d になります。\n", a, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2-x の解は、 %d と %d/%d になります。\n", a, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %d と %d/%d になります。\n", a, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %d と %d/%d になります。\n", a, b, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2+%dx の解は、 %d と %d/%d になります。\n", b, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 x^2+x+%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2+x の解は、 %d と %d/%d になります。\n", ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2+x%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 x^2+%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2 の解は、 %d と %d/%d になります。\n", ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 x^2-x+%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2-x の解は、 %d と %d/%d になります。\n", ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2-x%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 x^2%dx の解は、 %d と %d/%d になります。\n", b, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 x^2%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %d と %d/%d になります。\n", b, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+x の解は、 %d と %d/%d になります。\n", ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+x%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 -x^2+%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2 の解は、 %d と %d/%d になります。\n", ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2-x の解は、 %d と %d/%d になります。\n", ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2-x%d の解は、 %d と %d/%d になります。\n", c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c == 0) {
          printf("二次方程式 -x^2%dx の解は、 %d と %d/%d になります。\n", b, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai1, (-b - (int)sqrt(d)) / result1, 2 * a / result1);
      }
    }
  }
}

if (f == 6) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %d と %d/%d になります。\n", a, b, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d と %d/%d になります。\n", a, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+x の解は、 %d と %d/%d になります。\n", a, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %d と %d/%d になります。\n", a, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%d の解は、 %d と %d/%d になります。\n", a, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2 の解は、 %d と %d/%d になります。\n", a, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%d の解は、 %d と %d/%d になります。\n", a, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d と %d/%d になります。\n", a, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2-x の解は、 %d と %d/%d になります。\n", a, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %d と %d/%d になります。\n", a, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %d と %d/%d になります。\n", a, b, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d と %d/%d になります。\n", a, b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2+%dx の解は、 %d と %d/%d になります。\n", b, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 x^2+x+%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2+x の解は、 %d と %d/%d になります。\n", ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2+x%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 x^2+%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2 の解は、 %d と %d/%d になります。\n", ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 x^2-x+%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2-x の解は、 %d と %d/%d になります。\n", ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2-x%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2%dx の解は、 %d と %d/%d になります。\n", b, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %d と %d/%d になります。\n", b, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+x の解は、 %d と %d/%d になります。\n", ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+x%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 -x^2+%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2 の解は、 %d と %d/%d になります。\n", ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2-x の解は、 %d と %d/%d になります。\n", ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2-x%d の解は、 %d と %d/%d になります。\n", c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2%dx の解は、 %d と %d/%d になります。\n", b, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %d と %d/%d になります。\n", b, c, ikai2, (-b + (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }
  }
}

if (f == 7) {
  if (a > 1 || a < -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%dx+%d の解は、 %d/%d と %d/%d になります。\n", a, b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+%dx の解は、 %d/%d と %d/%d になります。\n", a, b, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+%dx%d の解は、 %d/%d と %d/%d になります。\n", a, b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 %dx^2+x+%d の解は、 %d/%d と %d/%d になります。\n", a, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2+x の解は、 %d/%d と %d/%d になります。\n", a, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2+x%d の解は、 %d/%d と %d/%d になります。\n", a, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 %dx^2+%d の解は、 %d/%d と %d/%d になります。\n", a, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2 の解は、 %d/%d と %d/%d になります。\n", a, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%d の解は、 %d/%d と %d/%d になります。\n", a, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2-x+%d の解は、 %d/%d と %d/%d になります。\n", a, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2-x の解は、 %d/%d と %d/%d になります。\n", a, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2-x%d の解は、 %d/%d と %d/%d になります。\n", a, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 %dx^2%dx+%d の解は、 %d/%d と %d/%d になります。\n", a, b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 %dx^2%dx の解は、 %d/%d と %d/%d になります。\n", a, b, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 %dx^2%dx%d の解は、 %d/%d と %d/%d になります。\n", a, b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }
  }

  if (a == 1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 x^2+%dx+%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2+%dx の解は、 %d/%d と %d/%d になります。\n", b, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2+%dx%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 x^2+x+%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2+x の解は、 %d/%d と %d/%d になります。\n", (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2+x%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 x^2+%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2 の解は、 %d/%d と %d/%d になります。\n", (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 x^2-x+%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2-x の解は、 %d/%d と %d/%d になります。\n", (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2-x%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 x^2%dx+%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 x^2%dx の解は、 %d/%d と %d/%d になります。\n", b, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 x^2%dx%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }
  }

  if (a == -1) {
    if (b > 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+%dx+%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+%dx の解は、 %d/%d と %d/%d になります。\n", b, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+%dx%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 1) {
      if (c > 0) {
          printf("二次方程式 -x^2+x+%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2+x の解は、 %d/%d と %d/%d になります。\n", (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2+x%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == 0) {
      if (c > 0) {
          printf("二次方程式 -x^2+%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2 の解は、 %d/%d と %d/%d になります。\n", (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b == -1) {
      if (c > 0) {
          printf("二次方程式 -x^2-x+%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2-x の解は、 %d/%d と %d/%d になります。\n", (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2-x%d の解は、 %d/%d と %d/%d になります。\n", c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }

    if (b < -1) {
      if (c > 0) {
          printf("二次方程式 -x^2%dx+%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c == 0) {
          printf("二次方程式 -x^2%dx の解は、 %d/%d と %d/%d になります。\n", b, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
      if (c < 0) {
          printf("二次方程式 -x^2%dx%d の解は、 %d/%d と %d/%d になります。\n", b, c, (-b + (int)sqrt(d)) / result1, 2 * a / result1, (-b - (int)sqrt(d)) / result2, 2 * a / result2);
      }
    }
  }
}

  while (1) {
    printf("\n引き続き二次方程式の解を算出しますか?(y/n) : ");
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