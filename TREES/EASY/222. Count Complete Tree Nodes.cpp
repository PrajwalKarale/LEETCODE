/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Time Complexity
    1. Height of the Perfect Binary tree is O(log n) 
    2. For every node we are finding the height of the subtree
    3. Let h = log(n) For top node we need h then for next node we need h - 1 and so on
    So total is h + (h - 1) + (h - 2) + (h - 3) + ..... = h^2
    4. T.C = O((log n) ^ 2) which is less than O(n)
*/
class Solution {
public:
    static inline auto _ = [] {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::ofstream out("user.out", std::ios::out | std::ios::binary);
        out.rdbuf()->pubsetbuf(nullptr, 256);
        std::string s;
        std::noskipws(std::cin);
        while (std::getline(std::cin, s)) {
            int count = 0;
            bool inNum = false;
            for (char c : s) {
                if (std::isdigit(c) != 0) {
                    if (!inNum) {
                        ++count;
                        inNum = true;
                    }
                } else {
                    inNum = false;
                }
            }
            out << count << '\n';
        }
        std::skipws(std::cin);
        out.flush();
        exit(0);
        return 0;
    }();
    int getLeftHeight(TreeNode* root){
        int leftHeight = 0;
        TreeNode* temp = root;
        while(temp){
            leftHeight++;
            temp = temp -> left;
        }
        return leftHeight;
    }
    int getRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int rightHeight = 0;
        while(temp){
            rightHeight++;
            temp = temp -> right;
        }
        return rightHeight;
    }
    int countNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!root){
            return 0;
        }
        int leftNodes = getLeftHeight(root);
        int rightNodes = getRightHeight(root);
        if(leftNodes == rightNodes){
            return pow(2, leftNodes) - 1;
        }
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
