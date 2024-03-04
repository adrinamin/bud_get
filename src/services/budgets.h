#ifndef BUDGETS_H
#define BUDGETS_H

#include "../data/budget.h"

/**
 * @brief Creates a budget.
 * 
 * This function is responsible for creating a budget.
 * It performs the necessary operations to initialize a budget object.
 * 
 * @return void
 */
void create_budget();

/**
 * @brief Retrieves all budgets.
 * 
 * This function is responsible for retrieving all budgets.
 * It performs the necessary operations to read all budgets from the file.
 * 
 * @param num_budgets The number of budgets.
 * 
 * @return Budget* The budgets.
 */
Budget *get_all_budgets(int *num_budgets);

#endif