#ifndef BUDGET_REPOSITORY_H
#define BUDGET_REPOSITORY_H

#include "../data/budget.h"

Budget *get_budgets(int *num_budgets);
Budget *get_budgets_by_account_name(char *account_name);
Budget get_budget_by_id(int id);
void add_budget(Budget budget);

#endif // BUDGET_REPOSITORY_H