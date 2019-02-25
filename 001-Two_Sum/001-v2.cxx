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
