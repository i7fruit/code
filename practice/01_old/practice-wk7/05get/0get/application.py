# Data can be passed in via URLs, akin to using HTTP GET
from flask import Flask

app = Flask(__name__)
@app.route("/show/<data>") # No spaces between angled brackets
def show(data):
    return "You passed in {}".format(data)