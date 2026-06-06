nums = [50, 11, 81, 44, 70, 30]

#first way
def greater1(num):
    greaterNum = num[0]
    for n in num:
        if n > greaterNum:
            greaterNum = n
    print(f"the entire list is {num} and the greater number is [{greaterNum}]")
    
greater1(nums)


#second way
def greater2(num):
    print(f"the entire list is {num} and the greater number is [{max(num, key=int)}]") #
    
greater2(nums)