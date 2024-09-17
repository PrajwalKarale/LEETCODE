/*
  Time Complexity:
    1. countWords method takes each word and inserts in map. Insertion in map takes O(1) time
    2. T.C -> O(N) where N is then total number of words present in the given string
  Space Complexity:
    1. We have created a map to store the frequency of the words
    2. S.C -> O(N) where N is the total number of words present in the string.
*/
class Solution {
public:
    void countWords(string s, unordered_map<string,int> &freq){
        istringstream iss(s);
        string word;
        while (iss >> word) {
            freq[word]++;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<string>result;
        unordered_map<string,int>freq;
        countWords(s1, freq);
        countWords(s2, freq);
        for(auto &it: freq){
            if(it.second == 1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
// @lc code=end
