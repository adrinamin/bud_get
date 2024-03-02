#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account_repository.h"
#include "../common/file_helper.h"
#include "../data/account.h"

FILE *csv_file = NULL; // Global variable to hold the file property

static Account *get_accounts_from_file(FILE *file);
static Account get_account_from_line(char *line);

Account *get_accounts(int *num_accounts) {
    if (csv_file == NULL) {
        csv_file = fopen("accounts.csv", "r");
    }
    if (csv_file == NULL) {
        printf("Error opening the file.\n");
        return NULL;
    }

    Account *accounts = get_accounts_from_file(csv_file);

    *num_accounts = count_lines(csv_file) - 1; // -1 because of the header

    fclose(csv_file);
    return accounts;
}

// void create_account(Account account)
// {
//     // Use the file_property variable here
// }

Account read_account()
{
    Account account = {
        .account_name = "Account 1",
        .bank_name = "Bank 1",
        .holder_name = "Holder 1",
        .amount = 100.0};
    return account;
}

// void update_account(Account account)
// {
//     // todo: implement
// }

// void delete_account(Account account)
// {
//     // todo: implement
// }

static Account *get_accounts_from_file(FILE *file)
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

static Account get_account_from_line(char *line)
{
  Account account;
  int token_index = 0;
  char *token = strtok(line, ",");
  while (token != NULL)
  {
    // We expect the line to have 4 tokens and the order is always the same.
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
