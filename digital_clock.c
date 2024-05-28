#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void fill_time(char *buffer, int format)
{
  time_t a;
  time(&a);
  struct tm *current_time;
  current_time = localtime(&a);
  if (format == 1)
  {
    strftime(buffer, 50, "%H:%M:%S", current_time);
  }
  else
  {
    strftime(buffer, 50, "%I:%M:%S %p", current_time);
  }
}
void fill_date(char *buffer)
{
  time_t a;
  time(&a);
  struct tm *current_time;
  current_time = localtime(&a);
  strftime(buffer, 100, "%A %B %d %Y", current_time);
}

int input_format()
{
  int format;
  printf("Which format will you choose:\n");
  printf("1: 24 hour format\n");
  printf("2: 12 hour format(default)\n");
  printf("Make your choice(1/2):\n");
  scanf("%d", &format);
  return format;
}

int main()
{
  char time[50], date[100];
  int format = input_format();

  while (1)
  {
    fill_time(time, format);
    fill_date(date);
    system("cls");
    printf("Current time: %s\n", time);
    printf("Current date: %s\n", date);
    sleep(1);
  }
  return 0;
}