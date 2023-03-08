from flask import Flask, render_template, request
import csv

app = Flask(__name__)

@app.route("/")
def index():
    """Displays the home page"""
    return render_template("index.html")

@app.route("/plug", methods=["POST"])
def register():
    """Gets information from the form filled"""
    name = request.form.get("name")
    device = request.form.get("device")

    if not name or not device:
        return render_template("failure.html")

    with open("devices.csv", "a") as f:
        writer = csv.writer(f)
        writer.writerow((name, device))

    return render_template("success.html")

@app.route("/process")
def process():
    """Prints the list of users to the devices.html page"""

    with open("devices.csv", "r") as f:
        reader = csv.reader(f)
        users = list(reader)

    return render_template("devices.html", users=users)