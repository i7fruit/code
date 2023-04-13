from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    # Checks the incoming REQUEST's ARGUMENTS ie the
    # incoming http parameters passed in, and
    # tries to GET something called NAME, then stores
    # it in the variable, name.
    name = request.args.get("foo", "placeholder value") # The second argument "placeholder value"
                                                        # is used if the user doesn't provide
                                                        # a value for "foo" in the url
    return render_template("index.html", bar=name)