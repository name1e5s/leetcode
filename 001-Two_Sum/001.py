#!/bin/env python3

# Runtime: 40 ms, faster than 73.58% of Python3 online submissions for Two Sum.
# Memory Usage: 14.3 MB, less than 5.08% of Python3 online submissions for Two Sum.

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for idx,num in enumerate(nums):
            if num in dic:
                return [dic[num], idx]
            dic[target - num] = idx
