#  Given a sorted list of integers nums and an integer target ,
# insert target into nums such that nums remains sorted. Return the index where the
# target is inserted.

import bisect 

class Solution :
    def insertIntoSortedArray(self,nums:list[int],target:int) -> int : 
        #bisect_left finds the insertion point for target in nums to maintain sorted order. 
        #It returns an insertion point which comes before (to the left of ) any existing entries of target in nums.
        
        index = bisect.bisect_left(nums,target)
        nums.insert(index,target)
        return index  
    

# Test cases
sol = Solution()
nums1 = [1, 3, 5, 7]
print(f"Original: {nums1}")
print(f"Inserted 4 at index: {sol.insertIntoSortedArray(nums1, 4)}") #
Expected: 2
print(f"Modified: {nums1}") # Expected: [1, 3, 4, 5, 7]
nums2 = [1, 3, 5, 7]
print(f"Original: {nums2}")
print(f"Inserted 0 at index: {sol.insertIntoSortedArray(nums2, 0)}") #
Expected: 0
print(f"Modified: {nums2}") # Expected: [0, 1, 3, 5, 7]
nums3 = [1, 3, 5, 7]
print(f"Original: {nums3}")
print(f"Inserted 7 at index: {sol.insertIntoSortedArray(nums3, 7)}") #
Expected: 3
print(f"Modified: {nums3}") # Expected: [1, 3, 5, 7, 7]
