#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/account.h"
#include "../common/file_helper.h"
#include "../common/string_helper.h"

static Account get_account_from_line(char *line);
static Account* get_accounts_from_file(FILE *file);

void create_account()
{
  printf("Creating a new account...\n");

  printf("Account name: ");
  char *account_name = malloc(MAX_ACCOUNT_NAME_SIZE);
  if (account_name == NULL)
  {
    printf("Error allocating memory.\n");
    exit(0);
  }
  fgets(account_name, MAX_ACCOUNT_NAME_SIZE, stdin);
  remove_newline(account_name);

  printf("Bank name: ");
  char *bank_name = malloc(MAX_BANK_NAME_SIZE);
  if (bank_name == NULL)
  {
    printf("Error allocating memory.\n");
    exit(0);
  }
  fgets(bank_name, MAX_BANK_NAME_SIZE, stdin);
  remove_newline(bank_name);

  printf("Holder name: ");
  char *holder_name = malloc(MAX_HOLDER_NAME_SIZE);
  if (holder_name == NULL)
  {
    printf("Error allocating memory.\n");
    exit(0);
  }
  fgets(holder_name, MAX_HOLDER_NAME_SIZE, stdin);
  remove_newline(holder_name);

  printf("Amount: ");
  float amount;
  scanf("%f", &amount);

  // Open file if exists, create it if it doesn't
  create_file("accounts.csv");

  // Open file
  FILE *file = fopen("accounts.csv", "a+");

  // Check if file is empty
  fseek(file, 0, SEEK_END);

  // Write header if file is empty
  long size = ftell(file);
  if (size == 0)
  {
    fprintf(file, "Account, Bank, Holder, Amount\n");
  }

  // Write account
  fprintf(file, "%s, %s, %s, %f\n", account_name, bank_name, holder_name,
          amount);

  /* Return memory */
  fclose(file);
  free(account_name);
  free(bank_name);
  free(holder_name);
}

Account* get_accounts(int* num_accounts)
{
  printf("\n");

  FILE *file = fopen("accounts.csv", "r");

  if (file == NULL)
  {
    printf("Error opening the file.\n");
    exit(0);
  }

  Account *accounts = get_accounts_from_file(file);

  *num_accounts = count_lines(file) - 1; // -1 because of the header

  fclose(file);
  
  return accounts;
}

static Account get_account_from_line(char *line)
{
  Account account;
  int token_index = 0;
  char *token = strtok(line, ",");
  while (token != NULL)
  {
    switch (token_index)
    {
    case 0:
      // printf("Account name: %s\n", token);
      strcpy(account.account_name, token);
      break;
    case 1:
      // printf("Bank name: %s\n", token);
      strcpy(account.bank_name, token);
      break;
    case 2:
      // printf("Holder name: %s\n", token);
      strcpy(account.holder_name, token);
      break;
    case 3:
      // printf("Amount: %f\n", atof(token));
      account.amount = atof(token);
      break;
    }
    token_index++;
    token = strtok(NULL, ",");
  }
  return account;
}

static Account* get_accounts_from_file(FILE *file)
{
  int size = 1; // initial size but it will grow
  Account *accounts = malloc(sizeof(Account));
  if (accounts == NULL)
  {
    printf("Error allocating memory.\n");
    exit(0);
  }

  char line[256];
  fgets(line, sizeof(line), file); // skip the first line because it is the header
  int i = 0;
  while (fgets(line, sizeof(line), file))
  {
    Account account = get_account_from_line(line);

    if (i >= size)
    {
      size++;
      accounts = realloc(accounts, size * sizeof(Account));
      if (accounts == NULL)
      {
        printf("Error reallocating memory.\n");
        exit(0);
      }
    }
    accounts[i] = account;
    i++;
  }

  return accounts;
}