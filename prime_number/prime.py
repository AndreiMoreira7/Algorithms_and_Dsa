import math

def prime():
    num = int(input("Enter a number and we'll tell you if it's prime: "))
    sqrt = int(math.sqrt(num))
    for i in range(num - 1, sqrt, -1):
        if num % i == 0:
            print(f"the number [{num}] isn't prime")
            return
    print(f"the number [{num}] is prime")

prime()