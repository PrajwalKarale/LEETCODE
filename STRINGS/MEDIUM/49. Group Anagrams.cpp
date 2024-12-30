/*
  Time Complexity:
    1. T.C -> O(n * k*log(k))
    2. n is the total length of the string vector and k is the length of each string
  Space Complexity:
    1. S.C -> O(n)
    2. Since we are using an unordered_map to store the strings.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string, vector<string>>mp;
        for(string &str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        for(auto it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};
