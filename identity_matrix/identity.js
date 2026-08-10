const verify = (matrix) => {
    const size = matrix.length 
    for(let i = 0; i < size; i++){
        for(let j = 0; j < size; j++){
            if((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)){
                console.log(`is not a matrix identity`)
                return
            }
        }
    }
    console.log(`is a matrix identity`)
}

testMatrix = [ 
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1]
]

verify(testMatrix)