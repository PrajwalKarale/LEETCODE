class Solution {
public:
    unordered_map<string, bool>memoize;
    bool isWordConcatenated(string word, unordered_set<string> &wordSet){
        if(memoize.find(word) != memoize.end()){
            return memoize[word];
        }
        for(int i = 0; i < word.length(); i++){
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i+1);
            if(
                (wordSet.find(prefix) != wordSet.end() && wordSet.find(suffix) != wordSet.end())
                ||
                (wordSet.find(prefix) != wordSet.end() && isWordConcatenated(suffix, wordSet))
              ){
                return memoize[word] = true;
            }
        }
        return memoize[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<string>result;
        unordered_set<string>wordSet(words.begin(), words.end());
        for(string &word: words){
            if(isWordConcatenated(word, wordSet)){
                result.push_back(word);
            }
        }
        return result;
    }
};
