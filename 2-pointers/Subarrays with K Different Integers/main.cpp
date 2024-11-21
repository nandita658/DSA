// Problem statement: https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
public:
    int atMost(vector<int> &nums, int k) {
        int l=0, r=0, ans=0;
        unordered_map<int, int> mp;
        while(r<nums.size()) {
            mp[nums[r]]++;
            while(mp.size() > k) {
                if(--mp[nums[l]] == 0) mp.erase(nums[l]); 
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k)-atMost(nums,k-1);
    }
};