const recursive_sum = (num) =>{
    let current = num.toString()

    while (current.length > 1){
        current = current
        .split("")
        .reduce((acc, digit) => acc + BigInt(digit), 0n)
        .toString()
    }
    console.log(`final result: ${current}`);
    return
}

let myTest = 999999999999999999999999999999999999999999n
recursive_sum(myTest)