#include <stdio.h>
#include <stdlib.h>

// int puzzle[9][9] = {
//     {3, 0, 0, 0, 2, 0, 0, 7, 0},
//     {9, 0, 0, 5, 0, 0, 0, 1, 4},
//     {0, 1, 6, 3, 7, 0, 0, 0, 8},
//     {2, 0, 0, 8, 0, 0, 0, 0, 1},
//     {5, 0, 0, 0, 4, 1, 8, 0, 0},
//     {0, 8, 9, 0, 0, 0, 0, 5, 0},
//     {0, 0, 5, 0, 1, 0, 2, 8, 0},
//     {0, 4, 0, 0, 0, 6, 0, 9, 3},
//     {7, 3, 1, 0, 8, 2, 0, 0, 0},
// };

void print_puzzle(int puzzle[9][9])
{
  printf("\n+-------+-------+-------+");
  for (int i = 0; i < 9; i++)
  {
    printf("\n");
    if (i % 3 == 0 && i != 0)
    {
      printf("|-------|-------|-------|\n");
    }
    for (int j = 0; j < 9; j++)
    {
      if (j % 3 == 0)
      {
        printf("| ");
      }
      if (puzzle[i][j] != 0)
      {
        printf("%d ", puzzle[i][j]);
      }
      else
      {
        printf("  ");
      }
    }
    printf("|");
  }
  printf("\n+-------+-------+-------+");
}

int valid_move(int puzzle[9][9], int row, int column, int value)
{
  for (int i = 0; i < 9; i++)
  {
    if (puzzle[row][i] == value)
    {
      return 0;
    }
  }

  for (int i = 0; i < 9; i++)
  {
    if (puzzle[i][column] == value)
    {
      return 0;
    }
  }

  int r = row - row % 3;
  int c = column - column % 3;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (puzzle[i + r][j + c] == value)
      {
        return 0;
      }
    }
  }

  return 1;
}

int is_solvable(int puzzle[9][9], int row, int column)
{
  if (column == 9)
  {
    if (row == 8)
    {
      return 1;
    }
    row++;
    column = 0;
  }

  if (puzzle[row][column] > 0)
  {
    return is_solvable(puzzle, row, column + 1);
  }

  for (int i = 1; i <= 9; i++)
  {
    if (valid_move(puzzle, row, column, i))
    {
      puzzle[row][column] = i;
      if (is_solvable(puzzle, row, column + 1))
      {
        return 1;
      }
      puzzle[row][column] = 0;
    }
  }
  return 0;
}

int main()
{
  int arr[9][9];

  printf("Enter unsolved sudoku(0 for blanked spaces):\n");
  printf("After entering unsolved sudoku then press any key to see the solution....\n");
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      scanf("%d ", &arr[i][j]);
    }
  }

  printf("Original Puzzle is:\n");
  print_puzzle(arr);
  if (is_solvable(arr, 0, 0))
  {
    printf("\n\n");
    printf("Solution of the above puzzle is:\n");
    print_puzzle(arr);
  }
  else
  {
    printf("This Puzzle is Unsolvable.\n");
  }
  return 0;
}