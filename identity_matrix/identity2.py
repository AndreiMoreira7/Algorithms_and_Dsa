import numpy as np #install numpy in terminal with "pip install numpy" before importing 

def verify(matrix):
    if np.allclose(matrix, np.eye(len(matrix))):
        print("is a matrix identity")
    else:
        print("is not a matrix identity")
    
matrix = np.array([
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1]
    ])

verify(matrix)