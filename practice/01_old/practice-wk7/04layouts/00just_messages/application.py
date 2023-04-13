from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/reg", methods=["POST"])
def reg():
    name = request.form.get("efa")
    device = request.form.get("device")

    if not name or not device:
        return render_template("failure.html")

    return render_template("success.html")