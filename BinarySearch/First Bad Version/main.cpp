// Problem statement: https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        int ans=n;
        while (l < r)
        {
            int m = l+(r-l)/2;
            if (isBadVersion(m))
            {
                ans = m;
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};