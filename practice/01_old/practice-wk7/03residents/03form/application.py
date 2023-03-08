from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/pullup", methods=["POST"])
def register():

    # When submitting info to a form via the method GET,
    # flask puts that info in a different place.

    # request.args contains all the info in the url that
    # are coming in from the users request

    # When submitting a users request via POST, the variable
    # request.form is used instead
    name = request.form.get("name")
    block = request.form.get("block")
    if not name or not block:
        return "Sorry! Unsuccessful registration."
    return render_template("success.html")