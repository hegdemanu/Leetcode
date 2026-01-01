class Solution:
    def isToLeft(self, mid: int, nums: List[int]) -> bool:
        if mid == len(nums) - 1:
            return True
        elif (mid % 2):#if its 0 -> false means this is true for odd
            return(nums[mid]!= nums[mid - 1])
        else: 
            return(nums[mid]!= nums[mid + 1])

    def singleNonDuplicate(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while (l <= r) :
            mid = (l+r) // 2
            if self.isToLeft(mid, nums) : 
                ans = nums[mid]
                r = mid - 1
            else : l = mid + 1
             
        return ans