import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    """Validates form's submission, writes the form's
    values to a csv file, and then redirects the user
    to /sheet"""

    name = request.form.get("name")
    phone = request.form.get("tname")
    device = request.form.get("device")

    # Got help for this line from:
    # https://stackoverflow.com/questions/32022568/get-value-of-a-form-input-by-id-python-flask
    gender = request.form.get("gender", "")

    if not name or not phone or not device or not gender:
        return render_template("error.html", message="Check required fields and resubmit form")

    # Writes form's data to a file
    with open("survey.csv", "a") as f:
        writer = csv.writer(f)
        writer.writerow((name, phone, device, gender))

    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    """Reads the file with the data and displays
    it on an html page"""

    with open("survey.csv", "r") as f:
        reader = csv.reader(f)
        users = list(reader)
    return render_template("userslist.html", users=users)
