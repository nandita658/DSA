// Problem statement: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
     int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int ans = 0,l = 0,r = 0,maxf = 0;
        while (r<s.length()) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            if ((r - l + 1) - maxf > k) {
                mp[s[l]] -= 1;
                l++;
            } else {
                ans = max(ans, (r - l + 1));
            }
            r++;
        }
        return ans;
    }
};