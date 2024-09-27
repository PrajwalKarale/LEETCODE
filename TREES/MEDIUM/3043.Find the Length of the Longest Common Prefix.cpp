/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
/*
    Time Complexity:
        1.  Consider there are m elements in arr1 so the 'insert' function will take O(m * D)
        where D is the largest number of digit in a number in arr1
        2. 'search' will also take O(D) where D is the largest number of digits in an element in arr2
        3. T.C -> O(mD + nD)
    Space Complexity
        1. S.C -> O(mD)
*/
struct TrieNode{
    char digit;
    TrieNode* children[10];
};
class Solution {
public:
    TrieNode* getNode(){
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 10; i++){
            node -> children[i] = nullptr;
        }
        return node;
    }
    void insert(int num, TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);
        for(char &ch: numStr){
            int index = ch - '0';
            if(crawl -> children[index] == nullptr){
                crawl -> children[index] = getNode();
            }
            crawl = crawl -> children[index];
        }
    }
    int search(int num, TrieNode* root){
        TrieNode *crawl = root;
        string numStr = to_string(num);
        int length = 0;
        for(char &ch: numStr){
            int index = ch - '0';
            if(crawl -> children[index]){
                length += 1;
                crawl = crawl -> children[index];
            }else{
                break;
            }
        }
        return length;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        TrieNode *root = getNode();
        for(int &num: arr1){
            insert(num, root);
        }
        int result = 0;
        for(int &num: arr2){
            result = max(result, search(num, root));
        }
        return result;
    }
};
// @lc code=end

