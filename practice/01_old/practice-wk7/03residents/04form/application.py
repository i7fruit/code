from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    name = request.args.get("resident", "you") # "you" is a placeholder value
    return render_template("index.html", person=name)

@app.route("/yo", methods=["POST"])
def enter():
    name = request.form.get("alpha")
    block = request.form.get("block")
    if not name or not block:
        return "Missing Name or Block"
    return render_template("success.html")