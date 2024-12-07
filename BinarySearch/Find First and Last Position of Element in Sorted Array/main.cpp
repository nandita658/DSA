// Problem statement: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end() || *lower != target) {
            return {-1, -1};
        }
        int start = lower - nums.begin();
        int end = upper - nums.begin() - 1;
        return {start, end};
    }
};