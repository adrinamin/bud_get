#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NAME_SIZE 100
#define MAX_BANK_NAME_SIZE 50
#define MAX_HOLDER_NAME_SIZE 50

int main_menu();
void help_page();
void create_account();
void get_accounts();
void get_budgets();
static void create_file(char *filename);
static void remove_newline(char *input);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    int option = main_menu();

    switch (option) {
    case 1:
      create_account();
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

  switch (argv[1][1]) {
  case 'a':
    printf("Listing accounts...\n");
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

void help_page() {
  printf("Usage: bud_get [OPTION]...\n");
  printf("List accounts or budgets.\n");
  printf("\n");
  printf("  -a,\tlist accounts\n");
  printf("  -b,\tlist budgets\n");
  printf("  -h,\tdisplay this help and exit\n");
  printf("\n");
}

int main_menu() {
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