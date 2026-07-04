def sum(my_list, target):
    my_set = {}
    for i in range(len(my_list) - 1):
        leftover = target - my_list[i]
        if leftover in my_set:
            print(f"the elements are in [{i}, {my_set[leftover]}]")
            return
        else:
            my_set.update({my_list[i]: i})        
        
    

my_list = [3, 8, 12, 17, 21, 25, 30, 32, 35, 40, 42, 45, 49, 52, 55]
target = 48
sum(my_list, target)