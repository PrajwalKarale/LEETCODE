// T.C -> For each position we have the option to chose and not to chose so if the the length of words is n so total is 2^n and then for each words[i] 
//we are checking whether the word should be taken of not so the total O(L * 2^n)

// S.C -> O(26) auxiliary space for storing the frequency
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int result;
    void solve(vector<string>&words, vector<char>&letters, vector<int>&score, vector<int>&freq, int i, int currentScore){
        result = max(result, currentScore);
        //Base Case
        if(i >= words.size()){
            return ;
        }
        //First let us check can we take words[i] or not
        int j = 0; 
        int tempScore = 0;
        vector<int>tempFreq = freq;
        while(j < words[i].length()){
            char ch = words[i][j];
            tempFreq[ch - 'a']--;
            tempScore  = tempScore + score[ch - 'a'];
            if(tempFreq[ch - 'a'] < 0){
                break;
            }
            j++;
        }
        if(j == words[i].length()){
            //Take that word
            solve(words,letters,score,tempFreq, i + 1, currentScore + tempScore);
        }
        // Skip that word
        solve(words,letters,score, freq, i + 1, currentScore);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        result = INT_MIN;
        for(char &ch: letters){
            freq[ch - 'a']++;
        }
        solve(words,letters,score,freq,0,0);
        return result;
    }
};
