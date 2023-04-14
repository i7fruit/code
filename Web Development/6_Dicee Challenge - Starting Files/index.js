// Randomly selects a number from 1 through 6
var randomNumber1 = Math.floor(Math.random() * 6) + 1;
var randomNumber2 = Math.floor(Math.random() * 6) + 1;

// Uses that number to select a dice image
var newSrcFile1 = "images/dice" + randomNumber1 + ".png";
var newSrcFile2 = "images/dice" + randomNumber2 + ".png";

// Changes the src attribute of the image tags
document.querySelector(".dice .img1").setAttribute("src", newSrcFile1);
document.querySelector(".dice .img2").setAttribute("src", newSrcFile2);

// Displays the winner
if (randomNumber1 > randomNumber2)
    document.querySelector("h1").textContent = "Player 1 wins";
else if (randomNumber2 > randomNumber1)
    document.querySelector("h1").textContent = "Player 2 wins";
else
    document.querySelector("h1").textContent = "It's a draw";