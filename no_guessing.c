#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  system("cls");
  int guess, random;
  srand(time(NULL));
  int no_of_guesses = 0;
  printf("Welcome in the world of guessing numbers:\n");
  printf("Guess a number between 1 to 100:-\n");
  random = rand() % 100 + 1;
  do
  {

    scanf("%d", &guess);
    no_of_guesses++;
    if (guess > random)
    {
      printf("Please guess a smaller number.\n\n");
    }
    else if (guess < random)
    {
      printf("Please guess a larger number.\n\n");
    }
    else
    {
      printf("\nCONGRATULATIONS, You have guessed the number in %d guesses.\n", no_of_guesses);
      printf("Thanks for playing.\n");
      printf("Created By: Kumkum Motwani\n");
    }
  } while (guess != random);
  return 0;
}