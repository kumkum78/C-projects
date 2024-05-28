#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 60
#define HEIGHT 20

int i, j, score, gameover;
int x, y, fruitX, fruitY, flag;
int tailX[100], tailY[100];
int nTail;

void setup()
{
  gameover = 0;
  x = WIDTH / 2;
  y = HEIGHT / 2;
  fruitX = rand() % WIDTH;
  fruitY = rand() % HEIGHT;
  score = 0;
}

void draw()
{
  // Use the Windows API to clear the screen instead of "system("cls")"
  COORD coord;
  coord.X = 0;
  coord.Y = 0;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

  for (i = 0; i < WIDTH + 2; i++)
    printf("#");
  printf("\n");

  for (i = 0; i < HEIGHT; i++)
  {
    for (j = 0; j < WIDTH; j++)
    {
      if (j == 0)
        printf("#");
      if (i == y && j == x)
        printf("O");
      else if (i == fruitY && j == fruitX)
        printf("F");
      else
      {
        int print = 0;
        for (int k = 0; k < nTail; k++)
        {
          if (tailX[k] == j && tailY[k] == i)
          {
            printf("o");
            print = 1;
          }
        }
        if (!print)
          printf(" ");
      }
      if (j == WIDTH - 1)
        printf("#");
    }
    printf("\n");
  }

  for (i = 0; i < WIDTH + 2; i++)
    printf("#");
  printf("\n");
  printf("Score: %d\n", score);
}

void input()
{
  if (_kbhit())
  {
    switch (_getch())
    {
    case 'w':
      flag = 1;
      break;
    case 's':
      flag = 2;
      break;
    case 'a':
      flag = 3;
      break;
    case 'd':
      flag = 4;
      break;
    case 'x':
      gameover = 1;
      break;
    }
  }
}

void logic()
{
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < nTail; i++)
  {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
  switch (flag)
  {
  case 1:
    y--;
    break;
  case 2:
    y++;
    break;
  case 3:
    x--;
    break;
  case 4:
    x++;
    break;
  default:
    break;
  }
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    gameover = 1;
  for (int i = 0; i < nTail; i++)
  {
    if (tailX[i] == x && tailY[i] == y)
      gameover = 1;
  }
  if (x == fruitX && y == fruitY)
  {
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score += 10;
    nTail++;
  }
}

int main()
{
  setup();
  while (!gameover)
  {
    draw();
    input();
    logic();
    Sleep(200);
  }
  printf("Game Over!\n");
  return 0;
}
