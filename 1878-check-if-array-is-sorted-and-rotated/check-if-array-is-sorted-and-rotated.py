class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt = 0
        s = (len(nums) - 1)
        if nums[s] > nums[0] : cnt += 1
        for i in range(1, s + 1):
            if nums[i-1] > nums[i] : cnt += 1
            if cnt > 1 : break
        return cnt <= 1
