const factorial = function () {
    let num = Number(prompt("input a number and we'll tell you its factorial"))
    for (n = num - 1; n != 1; n--) { 
        num *= n 
    }
    alert(num)
}

factorial()