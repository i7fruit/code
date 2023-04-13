from flask import Flask, render_template, request

# Tells Flask to make this file a webapp
app = Flask(__name__)

# Tells Flask that I want an app with
# a route listening for a "/" and once
# found, to call the function called index()
@app.route("/")
def index():
    return 'Hello, "CS50"! How\'s it going?'