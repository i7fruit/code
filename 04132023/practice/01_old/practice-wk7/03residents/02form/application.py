from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():

    # REMEMBER:
    # flask gives access to request.args,
    # which gives access to http parameters
    # and get which is built into that flask
    # feature, gives us access to a specific
    # parameter
    name = request.args.get("name")
    block = request.args.get("block")
    if not name or not block:
        return "Unsuccessful registration!\
        PS: There's also no success page to display anyway. \
        The 'request.args.get('name')' statement should read \
        'request.form.get('name')' because when information is \
        sent via POST, request.form should be used, not request.args"
    return render_template("success.html")