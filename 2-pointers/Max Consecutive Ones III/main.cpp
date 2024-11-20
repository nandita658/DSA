// Problem statement: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, n=nums.size();
        int l=0, r=0, countOfZeros=0;
        while(r<n) {
            if(nums[r] == 0) countOfZeros++;
            if(countOfZeros > k) {
                if(nums[l] == 0) countOfZeros--;
                l++;
            }
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};