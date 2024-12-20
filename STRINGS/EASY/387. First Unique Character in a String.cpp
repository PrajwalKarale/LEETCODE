/*
    Logic:
        1. Make the frequency Character array
        2. See the character whose count is 1
    Time Complexity:
        1. T.C -> O(n)
        2. n = len(string)
    Space Complexity;
        1. S.C -> O(n)
        2. Since we have used map to store the frequency of character
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(char &ch: s){
            mp[ch] += 1;
        }
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
