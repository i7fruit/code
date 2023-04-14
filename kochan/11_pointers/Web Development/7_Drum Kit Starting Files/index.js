// Selects elements in the drum class
var buttons = document.querySelectorAll(".drum");

// Iterates through buttons array listening for event
for (var i = 0, n = buttons.length; i < n; i++)
{
    buttons[i].addEventListener("click", function()
    {
        playSound(this.textContent);

        /**
         * Briefly changes text color of button clicked for 0.1 second
         * "this" gives the identity of the button that
         * triggered the event listener.
         */
        flashKey(this.textContent);
    });
}
/**
 * Listens for a keypress event on the document. "e" identifies the
 * event that triggered the event listener. The ".key" property gives
 * us the key on the keyboard that was tapped.
 */
document.addEventListener("keypress", function(e)
{
    playSound(e.key);
    flashKey(e.key);

});


function playSound(key)
{
    switch (key)
    {
        case "w":
            var sound = new Audio("sounds/crash.mp3");
            sound.play();
            break;
        case "a":
            var sound = new Audio("sounds/kick-bass.mp3");
            sound.play();
            break;
        case "s":
            var sound = new Audio("sounds/snare.mp3");
            sound.play();
            break;
        case "d":
            var sound = new Audio("sounds/tom-1.mp3");
            sound.play();
            break;
        case "j":
            var sound = new Audio("sounds/tom-2.mp3");
            sound.play();
            break;
        case "k":
            var sound = new Audio("sounds/tom-3.mp3");
            sound.play();
            break;
        case "l":
            var sound = new Audio("sounds/tom-4.mp3");
            sound.play();
            break;
        default:
            alert("Invalid sound output");
            break;
    }
}

/**
 * Briefly changes text color of button clicked for 0.1 second
 * "this" gives the identity of the button that
 * triggered the event listener.
 */
function flashKey(key)
{
    // Gets the class name of the button clicked
    var keyTapped = document.querySelector("." + key);

    // Changes the text color of the button to white
    keyTapped.style.color = "white";

    // Waits 1 millisecond, and returns to original color
    setTimeout(function()
    {
        keyTapped.style.color = "#da0463";
    }, 100);
}