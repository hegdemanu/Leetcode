class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt = 0
        if nums[(len(nums) - 1)] > nums[0] : cnt += 1
        for i in range(1, len(nums)):
            if nums[i-1] > nums[i] : cnt += 1
            if cnt > 1 : break
        return cnt <= 1
