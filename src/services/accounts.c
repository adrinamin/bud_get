#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/account.h"
#include "../common/file_helper.h"
#include "../common/string_helper.h"
#include "../repositories/account_repository.h"

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

  printf("Amount (hit enter for 0.0): ");
  float amount;
  // scanf("%f", &amount);
  if (scanf("%f", &amount) != 1)
  {
    // Usually when creating a new account, the amount is zero.
    amount = 0.0;
  }
  else if (amount < 0)
  {
    printf("Amount must be positive.\n");
    exit(0);
  }

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

Account *get_all_accounts(int *num_accounts)
{
  Account *accounts = get_accounts(num_accounts);
  return accounts;
}