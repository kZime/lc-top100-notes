
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        n = len(nums)

        # remove minus and 0
        for i in range(n):
            nums[i] = n+1 if nums[i] <= 0 else nums[i]

        # if nums[x-1] < 0 -> x already exist
        for i in range(n):
            x = abs(nums[i])
            if x <= n:
                nums[x - 1] = -abs(nums[x - 1])

        for i in range(n):
            if nums[i] > 0:
                return i + 1
        return n + 1

