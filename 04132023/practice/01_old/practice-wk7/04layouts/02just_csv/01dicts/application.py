from flask import Flask, render_template, request
import csv

app = Flask(__name__)

@app.route("/")
def index():
    """Returns the home page"""
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    """Retrieves user data from the posted form"""
    name = request.form.get("name")
    age = request.form.get("age")
    gender = request.form.get("gender")
    block = request.form.get("block")

    # Makes sure the user enters required information
    if not name or not age or not block:
        return render_template("failure.html")

    # Creates a file to store data
    with open("residents.csv", "a") as f:
        writer = csv.DictWriter(f, fieldnames=["name", "age", "gender", "block"])
        writer.writerow({"name": name, "age": age, "gender": gender, "block": block})

    return render_template("success.html")

@app.route("/resident")
def resident():
    with open("residents.csv", "r") as f:
        reader = csv.DictReader(f)
        students = list(reader)
    return render_template("residents.html", students=students)