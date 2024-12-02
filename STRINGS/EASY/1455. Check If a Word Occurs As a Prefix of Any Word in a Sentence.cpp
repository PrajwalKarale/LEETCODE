/*
  T.C -> O(N) where N is the total number of words in the string
  S.C -> O(1) since we are not using any extra Space
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool isPrefix(string s, string searchWord){
        if(searchWord.length() > s.length()){
            return false;
        }
        return s.substr(0, searchWord.size()) == searchWord;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int result = -1;
        int count = 0;
        stringstream s(sentence);
        string word;
        while(s >> word){
            if(isPrefix(word, searchWord)){
                result = count + 1;
                break;
            }
            count++;
        }
        return result;
    }
};
