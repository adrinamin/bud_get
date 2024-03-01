#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/budget.h"
#include "../common/file_helper.h"
#include "../common/string_helper.h"

#define AMOUNT_SIZE 100

static Budget get_budget_from_user_input();
static void save_budget_to_file(Budget budget);

void create_budget()
{
    printf("Creating a new budget...\n");

    Budget budget = get_budget_from_user_input();

    // print budget
    printf("\n");
    printf("Your new budget:\nbudget name: %s, budget amount: %.2f, budget account name: %s\n", budget.name, budget.amount, budget.account_name);
    printf("\n");

    create_file("budgets.csv");

    save_budget_to_file(budget);

    printf("Budget created successfully.\n");
}

static Budget get_budget_from_user_input()
{
    Budget budget;

    printf("Budget name: ");
    fgets(budget.name, BUDGET_NAME_SIZE, stdin);
    remove_newline(budget.name);

    printf("Do you want to create a budget with a specific amount? (y/n): ");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y')
    {
        printf("Amount: ");
        char *amount_str = malloc(AMOUNT_SIZE);
        fgets(amount_str, AMOUNT_SIZE, stdin);
        remove_newline(amount_str);
        budget.amount = atof(amount_str);
        free(amount_str);
    }
    else
    {
        budget.amount = 0.0;
    }
    clear_input_buffer();

    printf("Which account do you want to associate with this budget?\n");
    printf("Account name: ");
    fgets(budget.account_name, ACCOUNT_NAME_SIZE, stdin);
    remove_newline(budget.account_name);

    printf("generating a random id for the budget...\n");
    // Generate a random id
    uuid_t budget_id;
    uuid_generate_random(budget_id);
    char *budget_id_str = malloc(37);
    uuid_unparse(budget_id, budget_id_str);
    strcpy(budget.id, budget_id_str);
    free(budget_id_str);

    return budget;
}

static void save_budget_to_file(Budget budget)
{
    FILE *file = fopen("budgets.csv", "a");

    fseek(file, 0, SEEK_END);

    long size = ftell(file);
    if (size == 0)
    {
        fprintf(file, "id,name,amount,account_name\n");
    }

    fprintf(file, "%s,%s,%f,%s\n", budget.id, budget.name, budget.amount, budget.account_name);

    fclose(file);
}