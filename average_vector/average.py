def average():
    vector = []
    media = 0
    
    while True:
        verify = input("(y) if you want to input a number on array, (n) else: ")
        
        if verify.lower() == "y":
            num = (int(input("input some number on array: ")))
            vector.append(num)
            media += num
        elif verify.lower() == "n":
            break
        else:
            print("invalid option, please try again")
            
    if len(vector) != 0:
        media /= len(vector)
        print(f"the media is [{media}]")
    else:
        print("no number was inserted")  
        
average()