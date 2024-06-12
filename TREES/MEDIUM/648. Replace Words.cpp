auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
// Let us try this solution using TRIE data structure
class Solution {
public:
    struct trieNode{
        trieNode* children[26];
        bool isSet;
    };
    trieNode* root;
    trieNode* createNewNode(){
        // Here we are creating a new trieNode
        trieNode* newNode = new trieNode();
        // Since here new trieNode is created we dont know whether it is the last character of the word or not hence we are setting it to false
        newNode -> isSet = false;

        // Setting the children of the new node tu NULL
        for(int i = 0; i < 26; i++){
            newNode -> children[i] = NULL;
        }
        return newNode;
    }

    void insert(string word){
        trieNode* iterator = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(iterator -> children[index] == NULL){
                iterator -> children[index] = createNewNode();
            }
            iterator = iterator -> children[index];
        }
        // Since the crawler will reach at the 
        iterator -> isSet = true;
    }

    string search(string word){
        trieNode* iterator = root;
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(iterator -> children[index] == NULL){
                return word;
            }
            iterator = iterator -> children[index];
            if(iterator -> isSet){
                return word.substr(0, i+1);
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = createNewNode();
        for(string &word: dictionary){
            insert(word);
        }
        stringstream ss(sentence);
        string word;
        string result;
        while(getline(ss, word, ' ')){
            result = result + search(word) + " ";
        }
        result.pop_back();
        return result;
    }
};
