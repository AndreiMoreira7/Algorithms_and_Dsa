def average():
    vector = []
    res = 0
    
    while True:
        verify = input("(y) if you want to input a number on array, (n) else: ")
        
        if verify.lower() == "y":
            num = (int(input("input some number on list: ")))
            vector.append(num)
            res += num
        elif verify.lower() == "n":
            break
        else:
            print("invalid option, please try again")
            
    if len(vector) != 0:
        res /= len(vector)
        print(f"the list is {vector}, the media is [{res}]")
    else:
        print("no number was inserted")  
        
average()