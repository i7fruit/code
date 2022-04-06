import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Stores usernames
used_identifiers = []

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


# ***********************************************INDEX***************************************************INDEX
@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    items = db.execute("SELECT symbol, name, shares, price, total FROM purchases WHERE person_id = ?", session["user_id"])
    if not items:
        return apology("No data to display", 200)
    cash = 0.0
    # Gets value of cash user has
    money = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    for entry in money:
        cash = entry["cash"]

    # Gets total value of all stocks user has
    info = db.execute("SELECT SUM(total) FROM purchases WHERE person_id = ?", session["user_id"])

    for item in info:
        total = item["SUM(total)"]
        break

    TOTAL = cash + total

    return render_template("index.html", items=items, cash=usd(cash), TOTAL=usd(TOTAL))


# ***********************************************BUY*****************************************************BUY
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # POST
    if request.method == "POST":

        # Error checking
        info = lookup(request.form.get("symbol"))
        if not info:
            return apology("Missing or invalid symbol", 400)
        price = float(info["price"])
        shares_to_buy = request.form.get("shares")
        if not shares_to_buy:
            return apology("Missing share quantity", 400)

        # Checks if user keyed in an integer
        if shares_to_buy.isdigit() == False:
            return apology("Please enter an integer", 400)

        # Checks if user keyed in a positive integer
        shares_to_buy = int(shares_to_buy)
        if shares_to_buy < 0:
            return apology("Input only positive values for shares", 400)

        # Stores for later use
        qty_sought = shares_to_buy

        total = price * shares_to_buy
        cash = 0.0

        # Checks buyer's cash value
        available_cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        for entry in available_cash:
            cash = entry["cash"]
            break

        # Checks if user has enough funds to purchase stock
        if cash < total:
            return apology("Insufficient cash balance to make a purchase", 403)

        else:
            # Purchases stock
            cash -= total

            # If user owns any stocks...
            if db.execute("SELECT * FROM purchases WHERE person_id = ?", session["user_id"]):
                # ...checks if already owns stocks he wants to buy more of
                update = db.execute("SELECT shares, symbol FROM purchases WHERE person_id = ? AND symbol = ?",
                                    session["user_id"], info["symbol"])

                # If he does, updates number of shares owned
                if update:
                    for item in update:
                        if item["symbol"] == info["symbol"]:
                            shares_to_buy += item["shares"]
                            break

                    # Alters purchases table to reflect new number of shares
                    transaction_time = datetime.now()
                    db.execute("UPDATE purchases SET shares = ?, price = ?, buy = ?, sell = ?, total = ?, transaction_date = ? WHERE symbol = ?",
                               shares_to_buy, price, True, False, (shares_to_buy * price), transaction_time, info["symbol"])

                    # Keeps record of transaction
                    db.execute("INSERT INTO history (person_id, symbol, shares, price, transacted) VALUES (?, ?, ?, ?, ?)", session["user_id"], info["symbol"],
                               qty_sought, price, transaction_time)

                # ...else if he does not own those particular stocks...
                else:
                    # Inserts new row if stock not on the list of shares owned
                    transaction_time = datetime.now()
                    db.execute("INSERT INTO purchases (person_id, name, symbol, shares, price, buy, sell, total, transaction_date) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)",
                               session["user_id"], info["name"], info["symbol"], shares_to_buy, price, True, False, (shares_to_buy * price), transaction_time)

                    # Keeps record of transaction
                    db.execute("INSERT INTO history (person_id, symbol, shares, price, transacted) VALUES (?, ?, ?, ?, ?)", session["user_id"], info["symbol"],
                               qty_sought, price, transaction_time)

            # ...else if he doesn't own any stocks...
            else:
                # Inserts first row of purchases table if table contains nothing
                transaction_time = datetime.now()
                db.execute("INSERT INTO purchases (person_id, name, symbol, shares, price, buy, sell, total, transaction_date) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)",
                           session["user_id"], info["name"], info["symbol"], shares_to_buy, price, True, False, (shares_to_buy * price), transaction_time)

                # Keeps record of transaction
                db.execute("INSERT INTO history (person_id, symbol, shares, price, transacted) VALUES (?, ?, ?, ?, ?)", session["user_id"], info["symbol"],
                           qty_sought, price, transaction_time)

        # Updates cash value
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])
        flash("Bought!")
        return redirect("/")

    # POST
    return render_template("buy.html")


# ***********************************************HISTORY*************************************************HISTORY
@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    records = db.execute("SELECT * FROM history WHERE person_id = ?", session["user_id"])
    return render_template("history.html", records=records)


# ***********************************************LOGIN***************************************************LOGIN
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


# ***********************************************LOGOUT**************************************************LOGOUT
@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


# ***********************************************QUOTE***************************************************QUOTE
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # If form data is submitted via POST
    if request.method == "POST":
        info = lookup(request.form.get("symbol"))

        if not info:
            return apology("Enter a valid ticker symbol", 400)

        elif info["symbol"]:
            name = info["name"]
            symbol = info["symbol"]
            price = info["price"]

            return render_template("quoted.html", name=name, symbol=symbol, price=usd(price))

    # If page is requested via GET
    else:
        return render_template("quote.html")


# ***************************************REGISTER********************************************************REGISTER
@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # POST: if user submits registration form via post, insert details into database
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            return apology("Missing Username", 400)
        elif not password:
            return apology("Missing Password", 400)
        elif not confirmation:
            return apology("Please confirm password", 400)

        if password != confirmation:
            return apology("Password and Confirmation do not match", 400)

        # Checks for availability of username
        for entry in used_identifiers:
            if entry == username:
                return apology("Sorry! That username is unavailable.", 400)

        used_identifiers.append(username)

        # Inserts into database
        pw_confirm = generate_password_hash(confirmation)
        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                   username=username, hash=pw_confirm)

        return redirect("/login")

    # Displays registration form if request method is via GET
    else:
        return render_template("register.html")

# ***********************************************SELL****************************************************SELL


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # List to store stocks user owns
    stocks_list = []

    # Gets list of user's stocks
    if db.execute("SELECT symbol FROM purchases WHERE person_id = ?", session["user_id"]):
        stocks = db.execute("SELECT symbol FROM purchases WHERE person_id = ?", session["user_id"])
        for stock in stocks:
            stocks_list.append(stock["symbol"])

    else:
        return apology("No stocks available for sale", 400)

    # POST
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Please select a ticker symbol", 400)

        info = lookup(request.form.get("symbol"))
        if not info:
            return apology("Missing or invalid symbol", 400)
        shares_to_sell = request.form.get("shares")
        if not shares_to_sell:
            return apology("Missing share quantity", 400)
        # Checks if user keyed in an integer
        if shares_to_sell.isdigit() == False:
            return apology("Please enter an integer", 400)
        shares_to_sell = int(shares_to_sell)
        if shares_to_sell < 0:
            return apology("Enter positive value for shares", 400)

        # Checks seller's stock quantity
        qty_owned = 0
        shares_qty = db.execute("SELECT shares FROM purchases WHERE person_id = ? AND symbol = ?",
                                session["user_id"], info["symbol"])
        for entry in shares_qty:
            qty_owned = entry["shares"]
            break

        if qty_owned < shares_to_sell:
            return apology("Insufficient stocks balance to make a sale", 400)
        else:
            # Sells stock
            # If purchases data exists...
            if db.execute("SELECT * FROM purchases WHERE person_id = ?", session["user_id"]):
                update = db.execute("SELECT shares, symbol FROM purchases WHERE person_id = ? AND symbol = ?",
                                    session["user_id"], info["symbol"])

                # Updates number of shares owned
                if update:
                    for item in update:
                        if item["symbol"] == info["symbol"]:
                            qty_owned -= shares_to_sell
                            break
                    # Alters purchases table to reflect new number of shares
                    if qty_owned > 0:
                        transaction_time = datetime.now()
                        db.execute("UPDATE purchases SET shares = ?, price = ?, buy = ?, sell = ?, total = ?, transaction_date = ? WHERE symbol = ?",
                                   qty_owned, info["price"], False, True, (qty_owned * info["price"]), transaction_time, info["symbol"])

                        # Keeps record of transaction
                        db.execute("INSERT INTO history (person_id, symbol, shares, price, transacted) VALUES (?, ?, ?, ?, ?)", session["user_id"], info["symbol"],
                                   -(shares_to_sell), info["price"], transaction_time)
                    else:
                        transaction_time = datetime.now()
                        db.execute("DELETE FROM purchases WHERE symbol = ?", info["symbol"])
                        # Keeps record of transaction
                        db.execute("INSERT INTO history (person_id, symbol, shares, price, transacted) VALUES (?, ?, ?, ?, ?)", session["user_id"], info["symbol"],
                                   -(shares_to_sell), info["price"], transaction_time)

                else:
                    return apology("You do not own this stock", 400)

            else:
                return apology("You do not own this stock", 400)

            # Updates cash value
            user_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
            for entry in user_cash:
                cash = entry["cash"]

            cash += (shares_to_sell * info["price"])
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])
            flash("Sold!")
            return redirect("/")

    else:
        return render_template("sell.html", stocks_list=stocks_list)


# ****************************************CHANGE PASSWORD**********************************************************CHANGE PASSWORD
@app.route("/change_password", methods=["GET", "POST"])
@login_required
def change_password():
    """Changes the user's login password"""
    if request.method == "POST":
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")

        if not old_password:
            return apology("Enter your old password", 403)

        elif not new_password:
            return apology("Enter a new password", 403)

        elif not confirmation:
            return apology("Enter password confirmation", 403)

        # Checks if old password is correct
        pw_check = db.execute("SELECT hash FROM users WHERE id = ?", session["user_id"])

        if not check_password_hash(pw_check[0]["hash"], old_password):
            return apology("Your old password is incorrect", 403)

        if old_password == new_password:
            return apology("Cannot use old password as new", 403)

        if new_password != confirmation:
            return apology("New password and Confirmation do not match", 403)

        # Changes password
        password = generate_password_hash(confirmation)
        db.execute("UPDATE users SET hash = ? WHERE id = ?", password, session["user_id"])

        return redirect("/login")

    return render_template("change_password.html")


# ****************************************ERROR HANDLERS***********************************************************ERROR HANDLERS
def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# *****************************************LISTEN FOR ERRORS*******************************************************LISTEN FOR ERRORS
# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
