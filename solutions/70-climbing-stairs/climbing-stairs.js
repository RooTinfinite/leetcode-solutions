// JavaScript
var climbStairs = function (n) {
    var sqrt5 = Math.sqrt(5);
    var phi = (1 + sqrt5) / 2;
    var psi = (1 - sqrt5) / 2;
    return Math.floor((Math.pow(phi, n + 1) - Math.pow(psi, n + 1)) / sqrt5);
};