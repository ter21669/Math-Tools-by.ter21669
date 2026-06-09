#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int one_search(int p[], int time)
{
  for (int i = 0; i < time; i++)
  {
    if (p[i] == 1)
    {
      return 1;
    }
  }
  return 0;
}

int search(int pp[], int q, int timee)
{
  int qq = 0;
  for (int s = 0; s < timee; s++)
  {
    if (pp[s] == q)
    {
      qq += 1;
    }
  }
  return qq;
}

void score(int ppp[], int qqq[], int timeee, int cou[])
{
  qqq[0] = 0;
  qqq[1] = 0;
  while (1)
  {
    ppp[timeee - 1] = rand() % 13 + 1;
    if (cou[ppp[timeee - 1]] == 4)
    {
      continue;
    }
    else
    {
      cou[ppp[timeee - 1]] += 1;
      break;
    }
  }
  for (int ii = 0; ii < timeee; ii++)
  {
    qqq[0] += ppp[ii];
  }
  qqq[0] -= (search(ppp, 11, timeee) + (2 * search(ppp, 12, timeee)) + (3 * search(ppp, 13, timeee)));

  if (one_search(ppp, timeee) == 1 && qqq[0] <= 11)
  {
    qqq[1] = qqq[0] + 10;
  }
}

struct Player
{
  int streak;
  int total[2];
  int card[10];
  char c_card[14];
};

#define PLAYER_DEFAULT {0, {0}, {0}, "0A23456789TJQK"}

int main(void)
{
  char answer, ans, answ;
  int max_streak, max_streak1 = 0, t0, t1, res = 0, count[14];
  struct Player p1 = PLAYER_DEFAULT, d = PLAYER_DEFAULT;
  srand((unsigned int)time(NULL));

  puts("ブラックジャック - VER 1.1.2\n");
  FILE *fp = fopen("streak.txt", "r");
  if (fp == NULL)
  {
    puts("ファイル名:streak.txtを開けません。");
    printf("\n続行するには何かキーを押してください..."); scanf(" %c", &answer);
    return 1;
  }

  if (fscanf(fp, "%d", &max_streak) == 1)
  {
    printf("現在の最高連勝記録は%d勝です!\n", max_streak);
    p1.streak = 0;
  }
  else
  {
    puts("streak.txtに書いてある内容が適切ではありません。");
    printf("\n続行するには何かキーを押してください..."); scanf(" %c", &answer);
    return 1;
  }

  while (1)
  {

    for (int i57 = 0; i57 < 14; i57++)
    {
      count[i57] = 0;
    }
    t0 = 3;
    t1 = 3;
    p1.card[0] = rand() % 13 + 1;
    d.card[0] = rand() % 13 + 1;
    count[p1.card[0]] += 1;
    count[d.card[0]] += 1;

    score(p1.card, p1.total, 2, count);
    score(d.card, d.total, 2, count);
    puts("あなたのカードは次のようになります。");
    if (one_search(p1.card, 2) == 1)
    {
      printf("%c %c -> %d / %d\n\n", p1.c_card[p1.card[0]], p1.c_card[p1.card[1]], p1.total[1], p1.total[0]);
    }
    else
    {
      printf("%c %c -> %d\n\n", p1.c_card[p1.card[0]], p1.c_card[p1.card[1]], p1.total[0]);
    }
    puts("ディーラーのカードは次のようになります。");
    if (d.card[0] == 1)
    {
      printf("%c -> %d / %d\n\n", d.c_card[d.card[0]], 11, 1);
    }
    else
    {
      if (d.card[0] >= 11)
      {
        printf("%c -> %d\n\n", d.c_card[d.card[0]], 10);
      }
      else
      {
        printf("%c -> %d\n\n", d.c_card[d.card[0]], d.card[0]);
      }
    }

    if (p1.card[0] == 1 && p1.card[1] >= 10 || p1.card[0] >= 10 && p1.card[1] == 1)
    {
      puts("ブラックジャックだ! 君の勝ちだ!\n");
      Sleep(500);
      res = 1;
    }

    if (res == 0)
    {
      while (1)
      {
        printf("君は次どう勝負に出る? (h/H : Hit(もう一度引く) or s/S : Stand(引かない)) : ");
        scanf(" %c", &ans);
        while (getchar() != '\n')
          ;

        if (ans == 'h' || ans == 'H')
        {
          puts("君はHitを選んだね。どうなるかな?\n");

          score(p1.card, p1.total, t0, count);
          puts("あなたのカードは次のようになります。");
          for (int iii = 0; iii < t0; iii++)
          {
            printf("%c ", p1.c_card[p1.card[iii]]);
          }
          printf("-> ");
          if (p1.total[1] != 0)
          {
            printf("%d / %d\n\n", p1.total[1], p1.total[0]);
          }
          else
          {
            printf("%d\n\n", p1.total[0]);
          }

          if (p1.total[1] == 0 && p1.total[0] > 21)
          {
            puts("Bust! 22を超えてしまったね。君の負けだ。\n");
            Sleep(500);
            res = -1;
            break;
          }
          else
          {
            t0 += 1;
          }
        }
        else if (ans == 's' || ans == 'S')
        {
          puts("君はStandを選んだね。さあ、勝負だ!\n");
          res = 0;
          break;
        }
        else
        {
          puts("h/Hかs/Sを入力してください。\n");
        }
      }

      if (res == 0)
      {
        puts("ディーラーが二枚目のカードをめくりました。");
        if (one_search(d.card, 2) == 1)
        {
          printf("%c %c -> %d / %d\n\n", d.c_card[d.card[0]], d.c_card[d.card[1]], d.total[1], d.total[0]);
        }
        else
        {
          printf("%c %c -> %d\n\n", d.c_card[d.card[0]], d.c_card[d.card[1]], d.total[0]);
        }

        if (d.card[0] == 1 && d.card[1] >= 10 || d.card[0] >= 10 && d.card[1] == 1)
        {
          puts("ブラックジャックだ! 君の負けだ...\n");
          Sleep(500);
          res = 2;
        }
        if (p1.total[1] == 0 && d.total[1] == 0)
        {
          if (p1.total[0] < d.total[0])
          {
            puts("ディーラーがStandを選択しました。\n");
            puts("君の負けだ...\n");
            Sleep(500);
            res = 2;
          }
        }
        else if (p1.total[1] == 0)
        {
          if (p1.total[0] < d.total[1])
          {
            puts("ディーラーがStandを選択しました。\n");
            puts("君の負けだ...\n");
            Sleep(500);
            res = 2;
          }
        }
        else if (d.total[1] == 0)
        {
          if (p1.total[1] < d.total[0])
          {
            puts("ディーラーがStandを選択しました。\n");
            puts("君の負けだ...\n");
            Sleep(500);
            res = 2;
          }
        }
        else
        {
          if (p1.total[1] < d.total[1])
          {
            puts("ディーラーがStandを選択しました。\n");
            puts("君の負けだ...\n");
            Sleep(500);
            res = 2;
          }
        }

        if (res == 0)
        {
          while (1)
          {
            Sleep(500);
            puts("ディーラーがhitを選択しました。\n");

            score(d.card, d.total, t1, count);
            puts("ディーラーのカードは次のようになります。");
            for (int iiii = 0; iiii < t1; iiii++)
            {
              printf("%c ", d.c_card[d.card[iiii]]);
            }
            printf("-> ");
            if (d.total[1] != 0)
            {
              printf("%d / %d\n\n", d.total[1], d.total[0]);
            }
            else
            {
              printf("%d\n\n", d.total[0]);
            }

            if (d.total[1] == 0 && d.total[0] > 21)
            {
              puts("Bust! 22を超えました。君の勝ちだ!\n");
              res = -1;
              break;
            }
            else
            {
              t1 += 1;
              res = 0;
              if (p1.total[1] == 0 && d.total[1] == 0)
              {
                if (p1.total[0] < d.total[0])
                {
                  break;
                }
              }
              else if (p1.total[1] == 0)
              {
                if (p1.total[0] < d.total[1])
                {
                  break;
                }
              }
              else if (d.total[1] == 0)
              {
                if (p1.total[1] < d.total[0])
                {
                  break;
                }
              }
              else
              {
                if (p1.total[1] < d.total[1])
                {
                  break;
                }
              }
            }
          }
          Sleep(500);
          if (res == 0)
          {
            puts("ディーラーがStandを選択しました。\n");
            puts("君の負けだ...\n");
            res = 2;
          }
          else
          {
            res = 1;
          }
        }
      }
    }

    if (res == 1)
    {
      p1.streak += 1;
    }
    else
    {
      if (p1.streak > max_streak1)
      {
        max_streak1 = p1.streak;
      }
      p1.streak = 0;
    }
    printf("現在は%d連勝です。\n\n", p1.streak);

    while (1)
    {
      printf("引き続きゲームを行いますか? (y/Y or n/N) : ");
      scanf(" %c", &answ);
      while (getchar() != '\n')
        ;
      if (answ == 'y' || answ == 'Y')
      {
        puts("もう一試合、勝負だ!\n\n");
        res = 0;
        break;
      }
      else if (answ == 'n' || answ == 'N')
      {
        puts("ゲームを終了するね。\n\n");
        res = 1;
        break;
      }
      else
      {
        puts("y/Y若しくはn/Nを入力してください。\n");
        continue;
      }
    }

    if (res == 1)
    {
      break;
    }
  }

  if (max_streak1 > max_streak)
  {
    printf("連勝記録を更新しました!現在の最高連勝記録は%dです。\n", max_streak1);

    fclose(fp);
    FILE *fpw = fopen("streak.txt", "w");
    if (fpw == NULL)
    {
      puts("ファイル名:streak.txtを開けません。");
      printf("\n続行するには何かキーを押してください..."); scanf(" %c", &answer);
      return 1;
    }

    fprintf(fpw, "%d", max_streak1);
    fclose(fpw);
  }
  else
  {
    printf("連勝記録は更新できませんでした...現在の最高連勝記録は%dです。\n", max_streak);
    fclose(fp);
  }

  printf("\n続行するには何かキーを押してください..."); scanf(" %c", &answer);
  return 0;
}