#ifndef BUDGET_REPOSITORY_H
#define BUDGET_REPOSITORY_H

#include "../data/budget.h"

Budget *get_budgets(int *num_budgets);
Budget get_budget_by_id(int id);
void add_budget(Budget budget);
float get_total_budget_amount(char *account_name);

#endif // BUDGET_REPOSITORY_H