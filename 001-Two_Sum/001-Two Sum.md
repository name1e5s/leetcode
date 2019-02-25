Two Sum
=======================

众所周知的 LeetCode 第一题。题目如下：

> Given an array of integers, return indices of the two numbers such that they add up to a specific target.
>
> You may assume that each input would have exactly one solution, and you may not use the same element twice.

题意就是在给定的数组中存在两个数 `a` 和 `b` ，使得 `a + b = target`，我们需要返回这两个数的索引值。

显然这题我们只需要使用哈希表记录下标 `i` 以及和为 `target - nums[i]` 并在遍历时查找 `nums[i]` 是否在哈希表内即可。

C++ 实现如下：
```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rec;
        for(auto i = 0; i < nums.size(); i++) {
            auto ans = rec.find(nums[i]);
            if(ans != rec.end())
                return {ans->second, i};
            rec.insert(make_pair(target - nums[i], i));
        }
        return {0, 0}; // for the fucking leetcode's policy
    }
};
```
这里要注意，因为 LeetCode 开启了 `-Werror=return-type` 这一编译选项，我们在编写代码时需要注意在函数的最后也要写一条 `return` 语句，否则就会报错 “error: control may reach end of non-void function [-Werror=return-type]”。

将此代码提交，发现结果不尽如人意：
```
Runtime: 16 ms, faster than 57.75% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 46.35% of C++ online submissions for Two Sum.
```

我们知道，对于这个代码中的 `std::unordered_map::insert` 方法，我们可以使用 `C++11` 中出现的 `std::unordered_map::emplace` 方法进行替代。这一改动可以避免不必要的临时变量，据传闻可以提升运行效率。

改动后的代码以及运行结果如下：
```C++
// Runtime: 12 ms, faster than 97.81% of C++ online submissions for Two Sum.
// Memory Usage: 10.3 MB, less than 39.06% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rec;
        for(auto i = 0; i != nums.size(); i++) {
            auto ans = rec.find(nums[i]);
            if(ans != rec.end())
                return {ans->second, i};
            rec.emplace(target - nums[i], i);
        }
        return {0, 0};
    }
};
```

最后附上 `Python 3` 版本的实现（Python 赛高！）：
```Python
# Runtime: 40 ms, faster than 73.58% of Python3 online submissions for Two Sum.
# Memory Usage: 14.3 MB, less than 5.08% of Python3 online submissions for Two Sum.

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for idx,num in enumerate(nums):
            if num in dic:
                return [dic[num], idx]
            dic[target - num] = idx
```