from flask import Flask, render_template, request, redirect
from datetime import datetime
from pytz import timezone

app = Flask(__name__)

@app.route("/")
def index():
    tw = datetime.now(timezone("Asia/Taipei"))
    lag = datetime.now(timezone("Africa/Lagos"))
    ny = datetime.now(timezone("America/New_York"))
    return render_template("index.html", lag = lag, tw = tw, ny = ny)