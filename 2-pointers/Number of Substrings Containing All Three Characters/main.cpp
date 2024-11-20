// Problem statement: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// Intution, if we find the valid substring containing all the three letters, we
// can say that substrings formed with the previous chars, will also have the 
// the three characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int count=0;
        for(int i=0;i<s.length();i++) {
            lastSeen[s[i]-'a'] = i;
            // we will consider the minimum lastSeen index, as substrings 
            // formed by adding chars, previous to the min index, to the 
            // current index, will surely have the three character.
            count+=(1+min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
        return count;
    }
};