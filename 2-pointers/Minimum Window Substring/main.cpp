// Problem statement: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char, int> mpS, mpT;
        for(auto ch:t) mpT[ch]++;
        int l=0, r=0, formed=0, required=mpT.size();
        int ans[2] = {-1,0};
        while(r<s.size()) {
            char c=s[r];
            mpS[c]++;
            if(mpT[c] == mpS[c]) formed++;
            while(formed == required) {
                c=s[l];
                if(ans[0]==-1 || (r-l+1)<ans[0]) {
                    ans[0]=r-l+1;
                    ans[1]=l;
                }
                mpS[c]--;
                if(mpT.find(c) != mpT.end() && mpS[c] < mpT[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0]==-1 ? "" : s.substr(ans[1], ans[0]);
    }
};