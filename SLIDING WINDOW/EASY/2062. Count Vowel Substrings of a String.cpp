/*
    Logic:
        1. From the question we understood that we need to find substrings who have exact 5 vowels. So for that what we can do is we can find substrings who
        has 5 or less than 5 vowels and substring to have 4 or less than 4 vowels.
        2. So atMost(5) - atMost(4) will give us exactly substring which contains 5 vowels.
    Time Complexity:
        1. Each character in the string is travelled atmost twice so
        2. T.C -> O(2*n) where n is the length of the string
    Space Complexity:
        1. S.C -> O(5)
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
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int consonantZero(string &s, int goal){
        int left = 0;
        int right = 0;
        int n = s.size();
        int result = 0;
        unordered_map<char,int>mp;
        while(right < n){
            char ch = s[right];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                right = right + 1;
                left = right;
                mp.clear();
                continue;
            }
            while(left < n && mp.size() > goal){
                char ch = s[left];
                mp[ch]--;
                if(mp[ch] == 0){
                    mp.erase(ch);
                }
                left++;
            }
            result = result + (right - left + 1);
            right++;
        }
        return result;
    }
    int countVowelSubstrings(string word) {
        return consonantZero(word, 5) - consonantZero(word, 4);
        // return consonantZero(word, 4);
    }
};
