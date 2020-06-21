from flask import (Blueprint, render_template, abort, jsonify, request, redirect, url_for)
from model import db, save_db, delete_budget

import uuid

account_bp = Blueprint('account', __name__)


@account_bp.route("/")
def accounts():
    return render_template("account/accounts.html")


@account_bp.route("/add", methods=["GET", "POST"])
def add_account():
    return render_template("account/add.html")
    # return redirect(url_for("/"))
    # if request.method == "POST":
    #     account = {"ID": str(uuid.uuid4()), "name": request.form["name"], "account": request.form["account"], "budgets": []}
    #     db.append(account)
    #     save_db()
    #     return redirect(url_for("welcome"))
    # else:
    #     return render_template("add_account.html")


# bp.route("/remove_account/<int:index>", methods=["GET", "POST"])
# def remove_account(index):
#     try:
#         if request.method == "POST":
#             del db[index]
#             save_db()
#             return redirect(url_for("welcome"))
#         else:
#             return render_template("remove_account.html", account=db[index])
#     except IndexError:
#         abort(404)


# bp.route("/account/<int:index>")
# def account(index):
#     account = {}
#     budgets = []
#     try:
#         account = db[index]
#         budgets = account["budgets"]
#         return render_template("account.html", account=account, budgets=budgets, index=index, max_index=len(db)-1, budget_count=len(budgets))
#     except IndexError:
#         abort(404)


# @app.route("/add_budget/<int:index>", methods=["GET", "POST"])
# def add_budget(index):
#     account = {}
#     budgets = []
#     account = db[index]
#     if request.method == "POST":
#         # form has been submitted, process data
#         budget = {"ID": str(uuid.uuid4()), "name": request.form["name"], "amount": request.form["amount"]}
#         budgets = account["budgets"]
#         budgets.append(budget)
#         # account["budgets"] = budgets
#         save_db()
#         return redirect(url_for("account", index=len(db)-1))
#     else:
#         return render_template("add_budget.html", index=index)


# @app.route("/account/<int:aindex>/<string:id>")
# def remove_budget(aindex: int, id: str):
#     try:
#         accounts = delete_budget(id, aindex)
#         account = accounts[aindex]
#         budgets = account["budgets"]
#         return render_template("account.html", account=account, budgets=budgets, index=aindex, max_index=len(db)-1, budget_count=len(budgets))
#     except IndexError:
#         abort(404)


# @app.route("/api/accounts")
# def api_account_list():
#     return jsonify(db)


# @app.route("/api/account/<int:index>")
# def api_account(index):
#     try:
#         return db[index]
#     except IndexError:
#         abort(404)
