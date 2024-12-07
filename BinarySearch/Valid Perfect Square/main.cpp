// Problem statement: https://leetcode.com/problems/valid-perfect-square/description/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int l=1, r=num/2;
        while(l<=r) {
            int mid=(l+r)/2;
            cout << mid << " " << l << " " << r << endl;
            if(num%mid==0 && num/mid==mid) return true;
            if(num/mid<mid) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};