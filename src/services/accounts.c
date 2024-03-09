#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/account.h"
#include "../common/file_helper.h"
#include "../common/string_helper.h"
#include "../repositories/account_repository.h"

#define FILE_PATH "accounts.csv"

static Account create_account_from_user_input();
static float get_amount();

void create_account()
{
  printf("Creating a new account...\n");

  Account account = create_account_from_user_input();

  // print account
  printf("\n");
  printf("Your new account:\naccount name: %s, bank name: %s, holder name: %s, amount: %.2f\n", account.account_name, account.bank_name, account.holder_name, account.amount);
  printf("\n");

  // create it if it doesn't
  create_file(FILE_PATH);

  // Open file
  add_account(account);

  printf("Account created successfully.\n");
}

Account *get_all_accounts(int *num_accounts)
{
  Account *accounts = get_accounts(num_accounts);
  return accounts;
}

static Account create_account_from_user_input()
{
  Account account;

  printf("Account name: ");
  fgets(account.account_name, MAX_ACCOUNT_NAME_SIZE, stdin);
  remove_newline(account.account_name);

  printf("Bank name: ");
  fgets(account.bank_name, MAX_BANK_NAME_SIZE, stdin);
  remove_newline(account.bank_name);

  printf("Holder name: ");
  fgets(account.holder_name, MAX_HOLDER_NAME_SIZE, stdin);
  remove_newline(account.holder_name);

  printf("Amount (positive value): ");

  account.amount = get_amount();

  return account;
}

static float get_amount()
{
  float amount;
  while (scanf("%f", &amount) != 1 || amount < 0)
  {
    printf("Amount must be a positive value.\n");
    printf("Amount: ");
    clear_input_buffer();
  }
  if (amount == -0.00)
    amount = 0.00; // fix negative zero

  return amount;
}