#include <stdio.h>
#include <stdlib.h>

int main_menu();
void help_page();
void create_account();
void get_accounts();
void get_budgets();
static void create_file(char *filename);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    int option = main_menu();

    switch (option) {
    case 1:
      create_account();
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
  printf("You chose %i\n", option);
  return option;
}

void create_account() {
  printf("Creating a new account...\n");

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
  fprintf(file, "Account 2, My bank, My name, 1000\n");

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