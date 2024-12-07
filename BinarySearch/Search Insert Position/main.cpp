// Problem statement: https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto lowerBound = lower_bound(nums.begin(), nums.end(), target);
        int idx;
        if(lowerBound!=nums.end()) {
            idx=lowerBound-nums.begin();
        } else {
            idx=nums.size();
        }
        return idx;
    }
};