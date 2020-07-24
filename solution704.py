# Given a sorted array nums, return the index of the target int in the array. 
# If it doesn't exist in the array return -1

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        length = len(nums)
        left = 0
        right = length -1
        while left<=right:
            mid = int(left +(right-left)/2)
            if nums[mid]==target:
                return mid
            if nums[mid]>target:
                right = mid-1
            if nums[mid]<target:
                left= mid+1
                
        return -1
