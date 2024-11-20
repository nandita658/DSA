// Problem statement: https://leetcode.com/problems/fruit-into-baskets/

//My solution
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, maxLen=0, n=fruits.size(), k=2;
        unordered_map<int,int> mp;
        while(r<n) {
            if(mp.find(fruits[r]) == mp.end()) {
                mp.insert({fruits[r],1});
            } else {
                mp[fruits[r]]++;
            }
            if(mp.size()>k) {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};

//0ms solution
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lastFruit = -1, secondLastFruit = -1, lastFruitCount = 0, currMax = 0, res = 0;
        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit) currMax++;
            else currMax = lastFruitCount + 1;
            if (fruit == lastFruit) lastFruitCount++;
            else lastFruitCount = 1; 
            if (fruit != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            res = max(res, currMax);
        }
        return res;
    }
};