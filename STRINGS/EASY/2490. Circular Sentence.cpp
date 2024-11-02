/*
    Time Complexity: 
        1. Since we are traversing each and every word in the given sentence
        2. T.C -> O(n)
    Space Complexity:
        1. We have created an extra space to store the words
        2. S.C -> O(n)

*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
};
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        stringstream s(sentence);
        vector<string>words;
        string word;
        while(s >> word){
            words.push_back(word);
        }
        if(words.size() == 1 && words[0][0] != words[0][words[0].length() - 1]){
            return false;
        }
        for(int i = 1; i < words.size(); ++i){
            if(words[i][0] != words[i - 1][words[i-1].length() - 1]){
                return false;
            }
        }
        int n1 = words.size();
        if(words[n1 - 1][words[n1 - 1].length() - 1] != words[0][0]){
            return false;
        }
        return true;
    }
};
