/*
    Logic:
        1. Prefix Sum
    Time Complexity:
        1. T.C -> O(n + q) where n is the number of strings in the vector and q are the total number of queries
    Space Complexity:
        1. S.C -> O(n) since we created a prefix array
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>result;
        int n = words.size();
        vector<int>prefix(n+1, 0);
        unordered_set<char>s = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i];
            if(s.find(words[i].front()) != s.end() && s.find(words[i].back()) != s.end()){
                prefix[i+1]++;
            }
        }
        for(vector<int>&query: queries){
            int l = query[0];
            int r = query[1];
            result.push_back(prefix[r + 1] - prefix[l]);
        }
        return result;
    }
};
