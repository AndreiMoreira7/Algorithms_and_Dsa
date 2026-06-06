def factorial():
    num = int(input("input a number and we'll tell you its factorial: ")) 
    for n in range(num - 1, 1, -1): 
        num *= n
    print(num)
    
factorial()