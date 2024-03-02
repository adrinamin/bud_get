#ifndef BUD_GET_ACCOUNTS_H
#define BUD_GET_ACCOUNTS_H

#include "../data/account.h"

/**
 * @brief Creates a new account
 *
 * This function creates a new account by asking the user for the following information: 
 * - Account name
 * - Bank name
 * - Holder name
 * - Amount
 *
 * @return void
 *
 */
void create_account();

/**
 * @brief Lists all accounts
 * 
 * This function returns a list of all accounts
 * 
 * 
 * @return Account* 
 *
*/
Account* get_all_accounts(int* num_accounts);

#endif