let age = 19;

if (age < 18)
{
    document.write("You will be eligible to vote in " + (18 - age) + "years");
}

else if (age == 18)
{
    document.write("This year, you are eligible to vote");
}

else
{
    document.write("You are eligible to vote." + "<br />")
    document.write("You will be " + (age + 1) + " next year.")
}