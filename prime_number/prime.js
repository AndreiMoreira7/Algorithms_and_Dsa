const prime = function(){
    const num = Number(prompt("Enter a number and we'll tell you if it's prime: "))
    const sqrt = Math.sqrt(num) //square root
    for (let i = num - 1; i > sqrt; i--){
        if(num % i == 0){
            return alert(`the number ${num} isn't a prime`)
        }
    }
    return alert(`the number ${num} is a prime`)
}

prime()