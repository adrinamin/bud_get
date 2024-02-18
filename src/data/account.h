#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_ACCOUNT_NAME_SIZE 100
#define MAX_BANK_NAME_SIZE 50
#define MAX_HOLDER_NAME_SIZE 50

typedef struct
{
  char account_name[MAX_ACCOUNT_NAME_SIZE];
  char bank_name[MAX_BANK_NAME_SIZE];
  char holder_name[MAX_HOLDER_NAME_SIZE];
  float amount;
} Account;

#endif