/*
    Time Complexity:
        1. T.C -> O(N)
    Space Complexity:
        1. S.C -> O(N)
*/
const int fastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
struct TrieNode {
    TrieNode *children[26];
    bool isEnd;
};
class WordDictionary {
public:
    TrieNode *root;
    TrieNode* getNode(){
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 26; i++){
            node -> children[i] = nullptr;
        }
        node -> isEnd = false;
        return node;
    }
    WordDictionary() {
        root = getNode();
    }
    
    void addWord(string word) {
        TrieNode *crawler = root;
        for(char &ch: word){
            int index = ch - 'a';
            if(crawler -> children[index] == nullptr){
                crawler -> children[index] = getNode();
            }
            crawler = crawler -> children[index];
        }
        crawler -> isEnd = true;
    }
    
    bool searchUntill(TrieNode *root, string word){
        TrieNode *crawler = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(ch == '.'){
                for(int j = 0; j < 26; j++){
                    if(crawler -> children[j] != nullptr){
                        if(searchUntill(crawler -> children[j], word.substr(i + 1)) == true){
                            return true;
                        }
                    }
                }
                return false;
            }else if(crawler -> children[index] == nullptr){
                return false;    
            }
            crawler = crawler -> children[index];
        }
        return crawler != nullptr && crawler -> isEnd == true;
    }
    bool search(string word) {
        return searchUntill(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
