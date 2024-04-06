class Solution {
public:
    string removeVowels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // string vowels = "aeiou";
        // for(char c: vowels){
        //     s.erase(remove(s.begin(), s.end(), c), s.end());
        // }
        string result = "";
        set<char>vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < s.length(); i++){
            if(vowels.find(s[i]) == vowels.end()){
                result = result + s[i];
            }
        }
        return result;
    }
};
