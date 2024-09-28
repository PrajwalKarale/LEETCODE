/*
  Time Complexity
    1. T.C -> O(n * l)
    2. n is the number of words present and l is the length of the longest word 
  Space Complexity
    1. S.C -> O(26 * n * l)
    2. if a word contains 26 letters then that much space is needed to store that specific word
*/
struct TrieNode{
    TrieNode* children[26];
    bool isEnd = false;
};
class Solution {
public:
    TrieNode* getNode(){
        TrieNode *node = new TrieNode();
        for(int i = 0; i < 26; i++){
            node -> children[i] = nullptr;
        }
        return node;
    }
    void insert(string word, TrieNode* root){
        TrieNode* crawl = root;
        for(char &ch: word){
            int index = ch - 'a';
            if(crawl -> children[index] == nullptr){
                crawl -> children[index] = getNode();
            }
            crawl = crawl -> children[index];
        }
        crawl -> isEnd = true;
    }
    bool hasAllPrefixes(string word, TrieNode* root){
        TrieNode *crawl = root;
        for(char &ch: word){
            int index = ch - 'a';
            if(crawl -> children[index] == nullptr || !crawl -> children[index] -> isEnd){
                return false;
            }
            crawl = crawl -> children[index];
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        TrieNode* root = getNode();
        //Insert all the words in trie
        for(string &word: words){
            insert(word, root);
        } 
        string longestValidWord = "";
        for(string &word: words){
            if(hasAllPrefixes(word, root)){
                if(word.length() > longestValidWord.length() ||
                 word.length() == longestValidWord.length() && word < longestValidWord){
                    longestValidWord = word;
                }
            }
        }
        return longestValidWord;
    }
};
// @lc code=end

