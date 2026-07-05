const sum = (arr, target) =>{
    let myMap = new Map()
    for (let i = 0; i < arr.length; i++){
        let leftover = target - arr[i]
        if (myMap.has(leftover)){
            console.log(`the elements was found in [${i}, ${myMap.get(leftover)}]`)
            return
        }
        else{
            myMap.set(arr[i], i)
        }
    }
}

const myArr = [3, 8, 12, 17, 21, 25, 30, 32, 35, 40, 42, 45, 49, 52, 55]
const target = 48
sum(myArr, target)