from flask import Flask, render_template, request

app = Flask(__name__)

# List to store words from the wordlist file
WORDS = []

# Loads the list with the words from the file
with open("wordlist0", "r") as f:
    for line in f.readlines():
        WORDS.append(line.rstrip())

@app.route("/")
def index():
    """Renders the home page"""
    return render_template("index.html")

@app.route("/search")
def search():
    words = []
    q = request.args.get("q")
    for word in WORDS:
        if word.startswith(q):
            words.append(word)
    return render_template("search.html", words=words)