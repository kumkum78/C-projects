#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int you, computer;

int menu()
{
  int ch;
  printf("1. Rock\n");
  printf("2. Paper\n");
  printf("3. Scissor\n");
  printf("4. Exit\n\n");
  printf("Enter your choice: ");
  scanf("%d", &ch);
  return ch;
}

void setUp()
{
label:
  computer = rand() % 4;
  if (computer == 0)
  {
    goto label;
  }
  you = menu();
}

void mainGame()
{
  switch (you)
  {
  case 1:
    if (computer == 1)
    {
      printf("GAME DRAW\n");
      printf("Computer: Rock       You: Rock\n");
    }
    else if (computer == 2)
    {
      printf("YOU LOSE\n");
      printf("Computer: Paper      You: Rock\n");
    }
    else
    {
      printf("YOU WIN\n");
      printf("Computer: Scissor    You: Rock\n");
    }
    break;

  case 2:
    if (computer == 1)
    {
      printf("YOU WIN\n");
      printf("Computer: Rock       You: Paper\n");
    }
    else if (computer == 2)
    {
      printf("GAME DRAW\n");
      printf("Computer: Paper      You: Paper\n");
    }
    else
    {
      printf("YOU LOSE\n");
      printf("Computer: Scissor    You: Paper\n");
    }
    break;

  case 3:
    if (computer == 1)
    {
      printf("YOU LOSE\n");
      printf("Computer: Rock       You: Scissor\n");
    }
    else if (computer == 2)
    {
      printf("YOU WIN\n");
      printf("Computer: Paper      You: Scissor\n");
    }
    else
    {
      printf("GAME DRAW\n");
      printf("Computer: Scissor    You: Scissor\n");
    }
    break;

  case 4:
    exit(0);
    break;

  default:
    printf("INVALID CHOICE ENTERED\n");
  }
}

int main()
{
  srand(time(NULL));
  while (1)
  {
    system("cls");
    setUp();
    mainGame();
    printf("Press any key for continue playing....\n");
    getch();
  }
  return 0;
}