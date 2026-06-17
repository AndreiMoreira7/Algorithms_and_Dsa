def remove_duplicates(numsList):
    numsList = list(set(numsList))
    print(f"the list without duplicates is {numsList}")
    return

nums = [3, 5, 7, 3, 1, 1, 10, 3, 7, 5, 1, 10, 10]
remove_duplicates(nums)