//T.C -> Total number of words are n and each word is of L length
// Then while loop will run for n*l times and then again we need to find the substring
// which will take again l time so the overall T.C O(n*l*l)

//S.C -> Total number of words are n and each word length can be L so O(n*L)

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string findRoot(string word, unordered_set<string>&st){
        for(int i = 0; i < word.length(); i++){
            string root = word.substr(0, i);
            if(st.find(root) != st.end()){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st(begin(dictionary), end(dictionary));
        string result = "";

        //To break the sentence into words
        stringstream ss(sentence);
        //Acts as a tokenizer
        string word; 

        while(getline(ss, word, ' ')){
            result = result + findRoot(word, st) + " ";
        }
        result.pop_back();
        return result;
    }
};
