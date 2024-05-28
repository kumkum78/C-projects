#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int bar_length = 50;
const int max_task = 5;

struct task
{
  int progress;
  int id;
  int step;
};

void printing_bars(struct task *t)
{
  int bar_to_show = (t->progress * bar_length) / 100;
  printf("Task %d: [", t->id);
  for (int i = 0; i < bar_length; i++)
  {
    if (i < bar_to_show)
    {
      printf("=");
    }
    else
    {
      printf(" ");
    }
  }
  printf("] %d%%\n", t->progress);
}

int main()
{
  srand(time(NULL));
  struct task *t[max_task];
  for (int i = 0; i < max_task; i++)
  {
    t[i] = (struct task *)malloc(sizeof(struct task));
    t[i]->id = i + 1;
    t[i]->progress = 0;
    t[i]->step = rand() % 5 + 1;
  }
  int task_incomplete = 1;
  while (task_incomplete)
  {
    task_incomplete = 0;
    system("cls");
    for (int i = 0; i < max_task; i++)
    {
      t[i]->progress += t[i]->step;
      if (t[i]->progress > 100)
      {
        t[i]->progress = 100;
      }
      else if (t[i]->progress < 100)
      {
        task_incomplete = 1;
      }
      printing_bars(t[i]);
    }
    sleep(1);
  }
  printf("All Tasks Completed Successfully.\n");
  return 0;
}
