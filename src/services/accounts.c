#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NAME_SIZE 100
#define MAX_BANK_NAME_SIZE 50
#define MAX_HOLDER_NAME_SIZE 50

static void create_file(char *filename);
static void remove_newline(char *input);

void create_account() {
  printf("Creating a new account...\n");

  printf("Account name: ");
  char *account_name = malloc(MAX_ACCOUNT_NAME_SIZE);
  if (account_name == NULL) {
    printf("Error allocating memory.\n");
    exit(0);
  }
  fgets(account_name, MAX_ACCOUNT_NAME_SIZE, stdin);
  remove_newline(account_name);

  printf("Bank name: ");
  char *bank_name = malloc(MAX_BANK_NAME_SIZE);
  if (bank_name == NULL) {
    printf("Error allocating memory.\n");
    exit(0);
  }
  fgets(bank_name, MAX_BANK_NAME_SIZE, stdin);
  remove_newline(bank_name);

  printf("Holder name: ");
  char *holder_name = malloc(MAX_HOLDER_NAME_SIZE);
  if (holder_name == NULL) {
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
  if (size == 0) {
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

void get_accounts() {
  printf("\n");
  printf("Listing accounts...\n");

  FILE *file = fopen("accounts.csv", "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    exit(0);
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
  }

  fclose(file);
}

static void create_file(char *filename) {
  FILE *file = fopen(filename, "a+");

  if (file == NULL) {
    printf("Error opening/creating the file.\n");
    exit(0);
  }

  fclose(file);
}

static void remove_newline(char *input) {
  if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
    input[strlen(input) - 1] = '\0';
}