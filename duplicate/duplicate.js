const removeDuplicate = (arr) =>{
    arr = [...new Set(arr)]
    console.log(`the array without duplicates is [${arr}]`)
}

let myarr = [3, 5, 7, 3, 1, 1, 10, 3, 7, 5, 1, 10, 10]
removeDuplicate(myarr)