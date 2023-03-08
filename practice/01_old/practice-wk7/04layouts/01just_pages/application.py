from flask import Flask, render_template, request, redirect

# Configures app
app = Flask(__name__)

# Creates a list to store each driver's information
drivers = []

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/drivers_list")
def drivers_list():
    return render_template("driverslist.html", drivers=drivers)

@app.route("/ride", methods=["POST"])
def register():
    name = request.form.get("efa")
    car = request.form.get("car")
    transmission = request.form.get("transmission")

    if not name or not car or not transmission:
            return render_template("failure.html")

    # Conditional operator in python eg. variable = x if C else y
    trans = "a" if transmission == "manual" else "an"

    drivers.append(f"{name}'s {car} is {trans} {transmission} transmission vehicle")

    return redirect("/drivers_list")