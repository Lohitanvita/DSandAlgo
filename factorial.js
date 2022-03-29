// JavaScript source code
function factorial(n) {
    if (n < 0) {
        return -1
    }
    if (n <= 2) {
        return n;
    }
    if (n > 2) {
        return n * factorial(n - 1);
    }
}
function factorial1(n) {
    var result = n;
    if (n < 0) {
        return -1
    }
    if ((n === 0) || (n === 1)) {
        return 1;
    }
    while (n > 1) {
        n--;
        result = result * n;
    }
}

function factorial2(n) {
    if (n < 0) {
        return -1
    }
    if ((n === 0) || (n === 1)) {
        return 1;
    }
    for (var i = n - 1; i >= 1; i--) {
        n *= i;
    } return n;

    }



document.writeln(factorial(7))