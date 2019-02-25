// Runtime: 16 ms, faster than 57.75% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 46.35% of C++ online submissions for Two Sum.

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
        return {0, 0}; // for the fucking letcode's policy
    }
};
