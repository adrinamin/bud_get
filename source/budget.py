from flask import Flask, render_template, abort, jsonify
from model import db

app = Flask(__name__)


@app.route("/")
def welcome():
    return render_template("welcome.html", accounts=db)


@app.route("/account/<int:index>")
def account(index):
    try:
        account = db[index]
        return render_template("account.html", account=account, index=index, max_index=len(db)-1)
    except IndexError:
        abort(404)


@app.route("/api/accounts")
def api_account_list():
    return jsonify(db)


@app.route("/api/account/<int:index>")
def api_account(index):
    try:
        return db[index]
    except IndexError:
        abort(404)

# @app.route("/budget")
# def budget():
#     return "This is the budget page"

# counter = 0

# @app.route("/counter")
# def count_demo():
#     global counter
#     counter += 1
#     return "This page was served " + str(counter) + " times"
