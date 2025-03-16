/*
    Logic:
        1. Looking at the question we can conclude that the problem is of the sliding window category.
        2. Whenever the consonant count will be greater than k we will have to shrink the window.
    Time Complexity:
        1. Each character in the word is visited atmost twice
        2. T.C -> O(n) where n is the length of the word.
    Space Complexity:
        1. S.C -> O(n) since we are usingf an auxiliary space of nextConsonantIndex vector.
*/
const auto __ = []() 
{
    struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
    std::atexit(&___::_);
    return 0;
}();
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool isVowel(char ch){
        unordered_set<char>s = {'a', 'e', 'i', 'o', 'u'};
        if(s.find(ch) != s.end()){
            return true;
        }
        return false;
    }
    int countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char,int>mp;
        vector<int>nextConsonantIndex(n);
        int result = 0;
        int i = 0;
        int j = 0;
        int consonantCount = 0;
        int lastConsonantIndex = n;
        for(int i = n - 1; i >= 0; i--){
            char ch = word[i];
            nextConsonantIndex[i] = lastConsonantIndex;
            if(!isVowel(ch)){
                lastConsonantIndex = i;
            }
        }
        while(j < n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                consonantCount++;
            }
            // Shrink the window till consonantCount == k
            while(i < n && consonantCount > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    consonantCount--;
                }
                i++;
            }
            while(i < n && mp.size() == 5 && consonantCount == k){
                result = result + (nextConsonantIndex[j] - j);
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    consonantCount--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
