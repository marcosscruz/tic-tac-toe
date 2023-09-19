document.addEventListener("DOMContentLoaded", function () {
    const screen1 = document.getElementById("screen1");
    const screen2 = document.getElementById("screen2");
    const screen3 = document.getElementById("screen3");
    const modePvP = document.getElementById("modePvP");
    const modePvIA = document.getElementById("modePvIA");
    const returnHomeScreen1_2 = document.getElementById("returnHomeScreen1_2");
    const returnHomeScreen1_3 = document.getElementById("returnHomeScreen1_3");

    modePvP.addEventListener("click", function () {
        screen1.style.display = "none";
        screen2.style.display = "block";
    });

    modePvIA.addEventListener("click", function () {
        screen1.style.display = "none";
        screen3.style.display = "block";
    });

    returnHomeScreen1_2.addEventListener("click", function () {
        screen1.style.display = "block";
        screen2.style.display = "none";
        screen3.style.display = "none";
    });

    returnHomeScreen1_3.addEventListener("click", function () {
        screen1.style.display = "block";
        screen2.style.display = "none";
        screen3.style.display = "none";
    });
});
