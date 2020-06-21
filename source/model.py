"""
model.py
-----------
do not use a plain json file as production database!

"""

import json


def load_db():
    with open("accounts_db.json") as f:
        return json.load(f)

def delete_budget(id: str, account_index: int):
    budgets = []
    changed = False
    data = load_db()
    account = data[account_index]
    budgets = account["budgets"]
    for index, budget in enumerate(budgets):
        if budget["ID"] == id:
            del budgets[index]
            changed = True

    if changed:    
        account["budgets"] = budgets
        data[account_index] = account
        with open("accounts_db.json", "w") as f:
            data = json.dump(db, f, indent = 4, sort_keys = True)
    return data

def save_db():
    with open("accounts_db.json", "w") as f:
        return json.dump(db, f, indent = 4, sort_keys = True)

db = load_db()