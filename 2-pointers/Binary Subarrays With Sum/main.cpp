// Problem statement: https://leetcode.com/problems/binary-subarrays-with-sum/

// we are doing atmost as 0 is also there in the array which will give wrong
// count, if we write the code for directly counting for goal.

class Solution {
public:
    int atMostCount (vector<int>&nums, int goal) {
        if(goal < 0) return 0;
        int sum = 0, l = 0, r = 0, ans = 0;
        while(r<nums.size()) {
            sum+=nums[r];
            while(sum>goal) {
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostCount(nums, goal)-atMostCount(nums, goal-1);
    }
};