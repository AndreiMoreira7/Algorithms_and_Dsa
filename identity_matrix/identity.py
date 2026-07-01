def verify(my_list):
    for i in range(len(my_list)):
        for j in range(len(my_list)):
            if (i == j and my_list[i][j] != 1) or (i != j and my_list[i][j] != 0):
                print(f"the list {my_list} is not a identity")
                return
    print(f"the list {my_list} is a identity")
    return

my_list = [[1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]]
verify(my_list)