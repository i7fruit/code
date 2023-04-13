from flask import Flask, render_template, request

# Configures a webapp
app = Flask(__name__)

# Listens for get requests of "/"
@app.route("/")
def index():
    data = request.args.get("value")
    return render_template("index.html", foo=data)