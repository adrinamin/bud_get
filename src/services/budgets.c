#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../data/budget.h"
#include "../data/account.h"
#include "../common/string_helper.h"
#include "../repositories/account_repository.h"
#include "../repositories/budget_repository.h"

static Budget create_budget_from_user_input();
static void generate_random_id(Budget *budget);
static void get_user_input(char *input, int size);
static float get_account_rest(Budget new_budget, Account connected_account);

void create_budget()
{
    printf("Creating a new budget...\n");

    Budget budget = create_budget_from_user_input();

    // print budget
    printf("\n");
    printf("Your new budget:\nbudget name: %s, budget amount: %.2f, budget account name: %s\n", budget.name, budget.amount, budget.account_name);
    printf("\n");

    add_budget(budget);

    printf("Budget created successfully.\n");
}

Budget *get_all_budgets(int *num_budgets)
{
    Budget *budgets = get_budgets(num_budgets);
    return budgets;
}

static Budget create_budget_from_user_input()
{
    Budget budget;

    printf("Budget name: ");
    get_user_input(budget.name, BUDGET_NAME_SIZE);

    printf("Which account do you want to associate with this budget?\n");

    Account account;
    while (strcmp(account.account_name, budget.account_name) != 0)
    {
        printf("Account name: ");
        get_user_input(budget.account_name, ACCOUNT_NAME_SIZE);

        account = read_account_by(budget.account_name);

        if (strcmp(account.account_name, budget.account_name) != 0)
        {
            printf("Account not found. Try again\n");
            memset(account.account_name, 0, sizeof(account.account_name));
            continue;
        }
    }

    float account_rest = get_account_rest(budget, account);
    if (account_rest == 0)
    {
        printf("There is no money left in your account. Exiting...\n");
        exit(1);
    }

    printf("Current amount left in your account: %.2f\n", account_rest);
    printf("Do you want to create a budget with a specific amount? (y/n): ");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y')
    {
        printf("Amount: ");
        do
        {
            scanf("%f", &budget.amount);
            if (budget.amount < 0)
            {
                printf("Amount must be a positive value.\n");
                printf("Amount: ");
            }
            else if (budget.amount > account_rest)
            {
                printf("Amount must be less than or equal to what is left in your account.\n");
                printf("Current amount left in your account: %.2f\n", account_rest);
                printf("Amount: ");
            }
        } while (scanf("%f", &budget.amount) != 1 || budget.amount < 0 || budget.amount > account_rest);
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

static float get_account_rest(Budget new_budget, Account connected_account)
{
    float total_budgets = get_total_budget_amount(connected_account.account_name);

    return connected_account.amount - total_budgets;
}