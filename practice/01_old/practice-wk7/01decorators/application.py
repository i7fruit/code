# Gives access to the flask library
from flask import Flask, render_template, request

# Turns the file into a webapp
app = Flask(__name__)

# Listens for GET requests of "/"
@app.route("/")
def index():
    return render_template("index.html")

@app.route("/macaulay")
def mac():
    return render_template("macaulay.html")

@app.route("/fill_form")
def form():
    return render_template("fill_form.html")