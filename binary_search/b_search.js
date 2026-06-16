const search = (arr) =>{
    const res = Number(prompt(`pick a number on [${arr}] and we will tell you in how much steps we found it`))
    let [left, steps] = [0, 0]
    let right = arr.length - 1

    while(left <= right){
        steps++
        let middle = Math.floor(left + (right - left) / 2)

        if(res === arr[middle]){
            alert(`we found the number in ${steps} steps`)
            return
        }
        else if(res < arr[middle]){
            right = middle - 1
        }
        else{
            left = middle + 1
        }
    }
    alert("the number wasn't found")
}

const myarr = [11, 22, 33, 44, 55, 67, 77, 88, 99, 111]
search(myarr)