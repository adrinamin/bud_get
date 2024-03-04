#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/budget.h"
#include "../common/file_helper.h"
#include "../common/string_helper.h"
#include "../repositories/account_repository.h"
#include "../repositories/budget_repository.h"

#define FILE_PATH "budgets.csv"

static Budget get_budget_from_user_input();
static void save_budget_to_file(Budget budget);
static void generate_random_id(Budget *budget);
static void get_user_input(char *input, int size);

void create_budget()
{
    printf("Creating a new budget...\n");

    Budget budget = get_budget_from_user_input();

    // print budget
    printf("\n");
    printf("Your new budget:\nbudget name: %s, budget amount: %.2f, budget account name: %s\n", budget.name, budget.amount, budget.account_name);
    printf("\n");

    create_file(FILE_PATH);

    save_budget_to_file(budget);

    printf("Budget created successfully.\n");
}

Budget *get_all_budgets(int *num_budgets) {
    Budget *budgets = get_budgets(num_budgets);
    return budgets;
}

static Budget get_budget_from_user_input()
{
    Budget budget;

    printf("Budget name: ");
    get_user_input(budget.name, BUDGET_NAME_SIZE);
    clear_input_buffer();

    printf("Which account do you want to associate with this budget?\n");

    Account account;
    while (strcmp(account.account_name, budget.account_name) != 0)
    {
        printf("Account name: ");
        get_user_input(budget.account_name, ACCOUNT_NAME_SIZE);

        account = read_account_by(budget.account_name);

        // printf("DEBUG: account name -> %s\n", account.account_name);

        if (strcmp(account.account_name, budget.account_name) != 0)
        {
            printf("Account not found. Try again\n");
            memset(account.account_name, 0, sizeof(account.account_name));
            continue;
        }
    }

    printf("Do you want to create a budget with a specific amount? (y/n): ");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y')
    {
        printf("Amount: ");
        scanf("%f", &budget.amount);
    }
    else
    {
        budget.amount = 0.0;
    }

    generate_random_id(&budget);

    return budget;
}

static void get_user_input(char *input, int size)
{
    fgets(input, size, stdin);
    remove_newline(input);
}

static void generate_random_id(Budget *budget)
{
    uuid_t budget_id;
    uuid_generate_random(budget_id);
    char *budget_id_str = malloc(37);
    uuid_unparse(budget_id, budget_id_str);
    strcpy(budget->id, budget_id_str);
    free(budget_id_str);
}

static void save_budget_to_file(Budget budget)
{
    FILE *file = fopen(FILE_PATH, "a+");

    fseek(file, 0, SEEK_END);

    long size = ftell(file);
    if (size == 0)
    {
        fprintf(file, "id,name,amount,account_name\n");
    }

    fprintf(file, "%s,%s,%f,%s\n", budget.id, budget.name, budget.amount, budget.account_name);

    fclose(file);
}