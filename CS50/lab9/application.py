import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Gets data from the form submitted
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        if not name or not month or not day:
            return redirect("/")

        else:
            # Inserts the data into the birthdays database
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)",
            name, month, day)

        # TODO: Add the user's entry into the database

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        # Retrieves information from the birthdays database
        friends = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", friends=friends)


@app.route("/del", methods=["GET", "POST"])
def delete():
    if request.method == "POST":
        name = request.form.get("name")
        month = int(request.form.get("month"))
        day = int(request.form.get("day"))

        if not name or not month or not day:
            return redirect("/")

        contacts = db.execute("SELECT * FROM birthdays WHERE month = ? AND day = ?", month, day)

        print(contacts)

        for entry in contacts:
            if entry["month"] == month and entry["day"] == day:
                db.execute("DELETE FROM birthdays WHERE month = ? AND day = ?", month, day)
                break

        return redirect("/")

    else:
        friends = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", friends=friends)