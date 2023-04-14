$("h1").addClass("big-title margin-50");

$("button")[3].addEventListener("click", function()
{

    setTimeout(function()
    {
        $("h1").removeClass("big-title");
    }, 200);
});