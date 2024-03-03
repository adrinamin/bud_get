#ifndef ACCOUNT_REPOSITORY_H
#define ACCOUNT_REPOSITORY_H

#include "../data/account.h"


Account *get_accounts(int *num_accounts);
// static void create_account(Account account);
Account read_account_by(char *account_name);
// static void update_account(Account account);
// static void delete_account(Account account);

#endif // ACCOUNT_REPOSITORY_H