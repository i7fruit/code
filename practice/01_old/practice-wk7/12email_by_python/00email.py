# 00email.py
# Mon, Apr 29 2019 16:48hrs
# Connects to a mail server securely
import smtplib, ssl

# Defines parameters
smtp_server = 'smtp.gmail.com' # For gmail
port = 465

sender = 'yumac67@gmail.com' # Variable for email address
password = input("Password: ") # Variable to hold password

# Gets encryption context
context = ssl.create_default_context()

# Connects to the smpt server
with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
    server.login(sender, password)
    print("Logged In")