from flask import Flask, flash, render_template, request, session, redirect
from cs50 import SQL
from flask_session import Session
from werkzeug.security import generate_password_hash, check_password_hash
from helper import login_required

app = Flask(__name__)
app.secret_key = 'your_secret_key'

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db = SQL("sqlite:///name.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def portfolio():
    #shows the main page of my code
    user_id = session["user_id"]

    descriptions = db.execute("SELECT * FROM Description WHERE user_id= :user_id", user_id=user_id)
    return render_template("portfolio.html", descriptions=descriptions)


@app.route("/add_task", methods=["GET", "POST"])
@login_required
def add_task():
    # add task to the db
    user_id = session["user_id"]
    if request.method == "POST":
        task = request.form.get("task")
        task_description = request.form.get("task_description")
        priority = request.form.get("priority")
        Deadline = request.form.get("deadline")
        Complete = request.form.get("complete")
        #check if the form is filled or not.
        if not task or not task_description or not priority or not Complete or not Deadline:
            flash("Please fill out all the feilds")
            return render_template("add_task.html")
        #inserts into the portfolio page.
        db.execute(
            "INSERT INTO Description (user_id,task,task_description,due_date,priority,completed) VALUES (?,?,?,?,?,?)", user_id,
            task, task_description, Deadline, priority, Complete
        )
        flash("Data added to database")

        return redirect("/")

    else:
        return render_template("add_task.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    # making sure login is done well
    session.clear()

    if request.method == "POST":
        #checks for the athentication.
        if not request.form.get("username"):
            return render_template("failure.html", message="username missing")

        elif not request.form.get("password"):

            return render_template("failure.html", message="enter password correctly")

        rows = db.execute("SELECT  * FROM name WHERE username=?", request.form.get("username"))
        #checks for the password present in data base and value entered by the user.
        if len(rows) != 1 or not check_password_hash(rows[0]["password"], request.form.get("password")):

            return render_template("failure.html", message="password doesn't match")

        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else:
        return render_template("login.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    "Registering a new user"
    session.clear()
    if request.method == "POST":
        #checks for values that are inserted or not.
        if not request.form.get("username"):
            flash("Please enter a username.")
            return render_template("failure.html", message="username missing")

        elif not request.form.get("password"):
            flash("Please enter a password.")
            return render_template("failure.html", message="password missing")
        #checks for the typed passwords
        elif request.form.get("password") != request.form.get("confirmation"):
            flash("Passwords do not match.")
            return render_template("failure.html", message="password not matching")

        hash_password = generate_password_hash(request.form.get("password"))
        #inserts name into database that i have created
        db.execute("INSERT INTO name (username,password) VALUES (?,?)",
                   request.form.get("username"), hash_password)

        rows = db.execute("SELECT * FROM name WHERE username=?",
                          request.form.get("username"))

        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/logout")
def logout():
    # logout
    session.clear()

    # return to home page
    return redirect("/")


if __name__ == "__main__":
    app.run(debug=True)
