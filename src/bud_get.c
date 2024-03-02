#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "services/accounts.h"
#include "services/budgets.h"
#include "data/account.h"

static int main_menu();
static void help_page();
static void list_accounts();

int main(int argc, char *argv[])
{

  if (argc == 1)
  {
    int option = main_menu();

    switch (option)
    {
    case 1:
      create_account();
      break;
    case 2:
      create_budget();
      break;
    case 3:
      list_accounts();
      break;
    case 5:
      printf("Exiting...\n");
      exit(0);
      break;
    default:
      printf("bud_get: invalid option -- '%i'\n", option);
      break;
    }
    return 0;
  }

  switch (argv[1][1])
  {
  case 'a':
    list_accounts();
    break;

  case 'b':
    printf("Listing budgets...\n");
    break;

  case 'h':
    help_page();
    break;

  default:
    printf("bud_get: invalid option -- '%c'\n", argv[1][0]);
    printf("Try 'bud_get -h' for more information.\n");
    break;
  }

  return 0;
}

static void help_page()
{
  printf("Usage: bud_get [OPTION]...\n");
  printf("List accounts or budgets.\n");
  printf("\n");
  printf("  -a,\tlist accounts\n");
  printf("  -b,\tlist budgets\n");
  printf("  -h,\tdisplay this help and exit\n");
  printf("\n");
}

static int main_menu()
{
  printf("Welcome to bud_get!\n");
  printf("What do you want to do?\n");
  printf("\n");
  printf("Choose one of the following numbers:\n");
  printf("1. Create a new account\n");
  printf("2. Create a new budget\n");
  printf("3. List accounts\n");
  printf("4. List budgets\n");
  printf("5. Exit\n");

  printf("Option: ");
  int option;
  scanf("%i", &option);
  getchar(); // Remove \n from stdin
  return option;
}

static void list_accounts()
{
  printf("Listing accounts...\n");
  int size = 0;
  Account *accounts = get_all_accounts(&size);
  printf("Number of accounts: %i\n", size);
  // print accounts
  for (int j = 0; j < size; j++)
  {
    printf("%s, %s, %s, %.2f\n", accounts[j].account_name, accounts[j].bank_name,
           accounts[j].holder_name, accounts[j].amount);
  }
  free(accounts);
}