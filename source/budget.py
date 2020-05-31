from flask import (Flask, render_template, abort, jsonify, request, redirect, url_for)
from model import db, save_db
from scss_compiler_wrapper import initialize_scss

app = Flask(__name__)

initialize_scss(app)

@app.route("/")
def welcome():
    return render_template("welcome.html", accounts=db)


@app.route("/add_account", methods=["GET", "POST"])
def add_account():
    if request.method == "POST":
        account = {"name": request.form["name"], "account": request.form["account"], "budgets": []}
        db.append(account)
        save_db()
        return redirect(url_for("welcome"))
    else:
        return render_template("add_account.html")


@app.route("/remove_account/<int:index>", methods=["GET", "POST"])
def remove_account(index):
    try:
        if request.method == "POST":
            del db[index]
            save_db()
            return redirect(url_for("welcome"))
        else:
            return render_template("remove_account.html", account=db[index])
    except IndexError:
        abort(404)


@app.route("/account/<int:index>")
def account(index):
    account = {}
    budgets = []
    try:
        account = db[index]
        budgets = account["budgets"]
        return render_template("account.html", account=account, budgets=budgets, index=index, max_index=len(db)-1, budget_count=len(budgets))
    except IndexError:
        abort(404)


@app.route("/add_budget/<int:index>", methods=["GET", "POST"])
def add_budget(index):
    account = {}
    budgets = []
    account = db[index]
    if request.method == "POST":
        # form has been submitted, process data
        budget = {"name": request.form["name"], "amount": request.form["amount"]}
        budgets = account["budgets"]
        budgets.append(budget)
        # account["budgets"] = budgets
        save_db()
        return redirect(url_for("account", index=len(db)-1))
    else:
        return render_template("add_budget.html", index=index)


@app.route("/api/accounts")
def api_account_list():
    return jsonify(db)


@app.route("/api/account/<int:index>")
def api_account(index):
    try:
        return db[index]
    except IndexError:
        abort(404)
