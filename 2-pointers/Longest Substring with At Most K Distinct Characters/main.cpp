//Problem statement: https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM

#include <unordered_map>
#include <string>
using namespace std;

int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> freq;
    int l=0, r=0, maxLen=0;
    while(r<str.length()) {
        if(freq.find(str[r]) == freq.end()) {
            freq.insert({str[r], 1});
        } else {
            freq[str[r]]++;
        }
        if(freq.size() > k) {
            freq[str[l]]--;
            if(freq[str[l]] == 0) freq.erase(str[l]);
            l++;
        }
        maxLen=max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}