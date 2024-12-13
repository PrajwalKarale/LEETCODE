/*
TRIE:

Root
 ├── o
 │   ├── a
 │   │   ├── t
 │   │   │   ├── h (end of "oath")
 ├── p
 │   ├── e
 │       ├── a
 │           ├── t (end of "pea")
 ├── e
 │   ├── a
 │       ├── t (end of "eat")
 ├── r
     ├── a
         ├── i
             ├── n (end of "rain")
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
struct TrieNode{
    bool endOfWord;
    TrieNode* children[26];
    string word;
};
class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    TrieNode* getNode(){
        TrieNode *newNode = new TrieNode();
        newNode -> endOfWord = false;
        newNode -> word = "";
        for(int i = 0; i < 26; i++){
            newNode -> children[i] = nullptr;
        }   
        return newNode;
    }
    void insertInTrie(TrieNode* root, string& word){
        TrieNode* crawler = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(crawler -> children[index] == nullptr){
                crawler -> children[index] = getNode();
            }
            crawler = crawler -> children[index];
        }
        crawler -> endOfWord = true;
        crawler -> word = word;
    }
    void findWords(vector<vector<char>>&board, int i, int j, int rows, int columns, TrieNode* root, vector<string>&result){
        if(i < 0 || i >= rows || j < 0 || j >= columns){
            return;
        }
        if(board[i][j] == '$' || root -> children[board[i][j] - 'a'] == nullptr){
            return;
        }
        root = root -> children[board[i][j] - 'a'];
        if(root -> endOfWord == true){
            result.push_back(root -> word);
            root -> endOfWord = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(int i = 0; i < 4; i++){
            int newI = i + dx[i];
            int newJ = j + dx[j];
            findWords(board, newI, newJ, rows, columns, root, result);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>result;
        int rows = board.size();
        int columns = board[0].size();
        TrieNode* root = getNode();
        for(string &word: words){
            insertInTrie(root, word);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                char ch = board[i][j];
                if(root -> children[ch - 'a'] != nullptr){
                    findWords(board, i, j, rows, columns, root, result);
                }
            }
        }
        return result;
    }
};
