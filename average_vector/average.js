const average = () => {
    let array = []
    let num = 0
    let res = 0

    while (true){
        let verify = prompt("(y) if you want to input a number on array, (n) else: ").toLowerCase()

        if (verify === "y"){
            num = (Number(prompt("input some number on array: ")))
            array.push(num)
            res += num
        }
        else if(verify === "n"){
            break
        }
        else{
            alert("invalid option, please try again")
        }
    }
     if(array.length > 0){
            res /= array.length
            alert(`the array [${array}], the average [${res}]`)
        }
    else{
            alert("no number was inserted")
        }
}

average()