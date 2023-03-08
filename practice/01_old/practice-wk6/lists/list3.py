# list4.py
# Tue, 02.05.19 15:09hrs

# a list can be tacked on to another list
nums = [1, 2, 3]

nums[len(nums):] = [3, 45, 9]

print(nums)

nums[6:] = [3000, 489]  # [6:] also [len(nums):]
print(nums)