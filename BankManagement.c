#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char name[20];
int dip_amt, amt = 10000, acc_no, ac, count = 0;
int trans_amt;
int with_amt;

void divider()
{
  for (int i = 0; i < 50; i++)
  {
    printf("-");
  }
  printf("\n");
}

void menu()
{
  system("cls");
  printf("\nMENU\n");
  divider();
  printf("\n1.Deposit Money\n");
  printf("2.Withdraw Money\n");
  printf("3.Transfer Money\n");
  printf("4.Account Details\n");
  printf("5.Transaction Details\n");
  printf("6.Exit\n");
  divider();
}

void deposit_money()
{
  FILE *fptr = fopen("account.txt", "a");
  time_t tm;
  time(&tm);
  printf("\nDepositing Money\n");
  divider();
  printf("Enter amount to deposit:\n\n");
  scanf("%d", &dip_amt);
  printf("DEPOSITION SUCCESSFULLY\n");
  amt += dip_amt;
  printf("Rs %d deposited in your account.\nTotal Amount in bank: Rs %d.\n", dip_amt, amt);
  fprintf(fptr, "Rs %d deposited in your account.\nTotal Amount in your account: Rs %d\n", dip_amt, amt);
  fprintf(fptr, "Date & Time of the transaction: %s\n\n\n", ctime(&tm));
  count++;
  fclose(fptr);
  printf("press any key....\n");
  getch();
}

void withdraw_money()
{
  time_t tm;
  time(&tm);
  FILE *fptr = fopen("account.txt", "a");
  printf("Withdrawing Money\n");
  divider();
  printf("Enter the amount you want to withdraw:\n\n");
  scanf("%d", &with_amt);
  if (with_amt > amt)
  {
    printf("Insufficient Balance\n");
  }
  else
  {
    amt = amt - with_amt;
    divider();
    printf("Rs %d withdrawn successfully\n", with_amt);
    printf("Current Balance: Rs %d\n", amt);
    fprintf(fptr, "Rs %d withrawn from your account successfully.\nCurrent Balance of your account: Rs %d\n", with_amt, amt);
    fprintf(fptr, "Date and Time of withdrawal : %s\n\n\n", ctime(&tm));
    count++;
  }
  fclose(fptr);
  printf("press any key....\n");
  getch();
}

void transfer_money()
{
  time_t tm;
  time(&tm);
  FILE *fptr = fopen("account.txt", "a");
  printf("TRANSFERING MONEY\n");
  divider();
  printf("Enter the account no. in which you want to transfer money:\n");
  scanf("%d", &ac);
  printf("Enter the amount you want to transfer:\n");
  scanf("%d", &trans_amt);
  if (trans_amt > amt)
  {
    divider();
    printf("Insufficient Balance\n");
  }
  else
  {
    divider();
    amt -= trans_amt;
    printf("Transaction Successful\n");
    printf("Rs %d transfered in account %d\n", trans_amt, ac);
    printf("Current amount left: Rs %d\n", amt);
    fprintf(fptr, "Rs %d transfered in account %d\n", trans_amt, ac);
    fprintf(fptr, "Current amount left: Rs %d\n", amt);
    fprintf(fptr, "Date and Time of transaction: %s\n\n\n", ctime(&tm));
    count++;
  }
  fclose(fptr);
  printf("press any key....\n");
  getch();
}

void checkDetails()
{
  printf("ACCOUNT DETAILS\n");
  divider();
  printf("\nName: %s\n", name);
  printf("Account no.: %d\n", acc_no);
  printf("Total Balance: %d\n", amt);
  printf("\nTotal transactions made from your accont: %d\n", count);
  printf("press any key....\n");
  getch();
}

void transaction_details()
{
  system("cls");

  FILE *fptr = fopen("account.txt", "r");
  char c = fgetc(fptr);
  if (c == EOF)
  {
    printf("NO RECENT TRANSACTION\n");
    divider();
  }
  else
  {
    printf("TRANSACTION DETAILS\n");
    divider();
    printf("\n%d transactions have been made from your account\n\n", count);
    while (c != EOF)
    {
      printf("%c", c);
      c = fgetc(fptr);
    }
  }
  fclose(fptr);
  printf("press any key....\n");
  getch();
}

void lastDetail()
{
  printf("ACCOUNT DETAILS\n");
  divider();
  printf("\nName: %s\n", name);
  printf("Account no.: %d\n", acc_no);
  printf("Total Balance: %d\n", amt);

  printf("\n\nPress any key to exit......\n");
  getch();
}

int main()
{
  system("cls");
  FILE *fptr = fopen("account.txt", "w");

  int choice;

  printf("Enter your name: ");
  gets(name);
  fprintf(fptr, "Name: %s\n", name);
  printf("Enter your account no. : ");
  scanf("%d", &acc_no);
  fprintf(fptr, "Account no.: %d\n\n\n", acc_no);

  fclose(fptr);

  while (1)
  {
    menu();
    printf("\nEnter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      system("cls");
      deposit_money();
      break;

    case 2:
      system("cls");
      withdraw_money();
      break;

    case 3:
      system("cls");
      transfer_money();
      break;

    case 4:
      system("cls");
      checkDetails();
      break;

    case 5:
      system("cls");
      transaction_details();
      break;

    case 6:
      system("cls");
      lastDetail();
      exit(0);

    default:
      printf("INVALID CHOICE\n");
    }
  }
  return 0;
}