#include <stdio.h>

void main_menu();
void help_page();

int main(int argc, char *argv[]) {

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