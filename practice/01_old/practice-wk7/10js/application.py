from flask import Flask, render_template, request
import csv

app = Flask(__name__)

@app.route("/")
def index():
    """Returns home page"""
    return render_template("index.html")

@app.route("/push", methods=["POST"])
def push():
    name = request.form.get("name")
    phone = request.form.get("phone")
    country = request.form.get("country")

    if not name or not phone or not country:
        return render_template("failure.html")

    with open("contacts.csv", "a") as f:
        writer = csv.DictWriter(f, fieldnames=["name", "phone", "country"])
        writer.writerow({"name": name, "phone": phone, "country": country})

    return render_template("success.html")

@app.route("/friends")
def friends():
    with open("contacts.csv", "r") as f:
        reader = csv.DictReader(f)
        contacts = list(reader)

    return render_template("contacts.html", contacts=contacts)