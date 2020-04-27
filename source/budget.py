from flask import Flask

app = Flask(__name__)


@app.route("/")
def welcome():
    return "This will be the budget app"

@app.route("/budget")
def budget():
    return "This is the budget page"

counter = 0

@app.route("/counter")
def count_demo():
    global counter
    counter += 1
    return "This page was served " + str(counter) + " times"
