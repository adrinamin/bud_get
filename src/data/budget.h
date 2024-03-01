#ifndef BUDGET_H
#define BUDGET_H

#define ID_SIZE 50
#define ACCOUNT_NAME_SIZE 100
#define BUDGET_NAME_SIZE 100
#define AMOUNT_SIZE 100

typedef struct {
    char id[ID_SIZE];
    char name[BUDGET_NAME_SIZE];
    float amount;
    char account_name[ACCOUNT_NAME_SIZE];
} Budget;

#endif