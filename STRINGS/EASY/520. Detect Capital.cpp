class Solution {
public:
    bool detectCapitalUse(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int wordLength = word.length();
        int capital = 0;
        for(char &c: word){
            if(c >= 'A' && c <= 'Z'){
                capital++;
            }
        }
        if(capital == wordLength){
            return true;
        }
        if(capital == 0){
            return true;
        }
        if(capital == 1 && word[0] >= 'A' && word[0] <= 'Z'){
            return true;
        }
        return false;
    }
};
