const greater = function(nums){
    let greaterNum = nums[0]
    for (let n = 0; n < nums.length; n++){
        if(nums[n] > greaterNum){
            greaterNum = nums[n]
        }
    } 
    console.log(`the entire array is [${nums}] and the greater number is [${greaterNum}]`)
}

let nums = [50, 11, 81, 44, 70, 30] //example of input
greater(nums)