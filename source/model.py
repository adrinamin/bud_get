"""
model.py
-----------
do not use a plain json file as production database!

"""

import json


def load_db():
    with open("accounts_db.json") as f:
        return json.load(f)

def save_db():
    with open("accounts_db.json", "w") as f:
        return json.dump(db, f, indent = 4, sort_keys = True)

db = load_db()