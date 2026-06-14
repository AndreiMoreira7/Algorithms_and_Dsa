def search(nums):
    res = int(input(f"pick a number in {nums} and we will tell you in how much steps we found it: "))
    left, steps = 0, 0
    right = len(nums) - 1
    
    while left <= right:
        middle = left + (right - left) // 2
        steps += 1
        
        if res == nums[middle]:
            print(f"the number was found in [{steps}] steps")
            return
        elif res > nums[middle]:
            left = middle + 1
        else:
            right = middle - 1
        
nums_example = [11, 22, 33, 44, 55, 67, 77, 88, 99, 111]

search(nums_example)