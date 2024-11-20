//Problem statement: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, maxSum;
        for(int i = 0; i < k; i++) sum += cardPoints[i];
        maxSum = sum;
        for(int i = 0; i<k; i++) {
            sum -= cardPoints[k-i-1];
            sum += cardPoints[n-i-1];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};