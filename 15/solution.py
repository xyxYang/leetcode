"""
因为要求答案不唯一，因此使用了效率不是很高的方法来排重
"""

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        ret = list()
        for i in xrange(len(nums) - 1):
            num1 = nums[i]
            lines = self.twoSum(nums[i+1:], -num1)
            for line in lines:
                num2 = line[0]
                num3 = line[1]
                ret_line = (num1, num2, num3)
                if ret_line not in ret:
                    ret.append((num1, num2, num3))
        return ret
    
    def twoSum(self, nums, value):
        i = 0
        j = len(nums) - 1
        ret = list()
        while i < j:
            if nums[i] + nums[j] == value:
                ret.append([nums[i], nums[j]])
                i += 1
                j -= 1
            elif nums[i] + nums[j] < value:
                i += 1
            elif nums[i] + nums[j] > value:
                j -= 1
            else:
                assert False
        return ret
        
