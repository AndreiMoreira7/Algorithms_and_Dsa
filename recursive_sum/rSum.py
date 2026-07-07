def recursive_sum():
    num = int(input("input the number: "))
    while True:
        num = list(int(character) for character in str(abs(num)))
        print(num)
        num = sum(num)
        if num < 10:
            print(int(num))
            return
    
recursive_sum()