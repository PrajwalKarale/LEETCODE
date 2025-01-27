// @lc code=start
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
    Logic:
        1. The node in the left subtree should be less than its parent and node in the right subtree should be greater than its parent
        2. We have to check each node is lying within the given subrange or not
    Time Complexity:
        1. TC -> O(n) where n is the total number of nodes present in the tree
    Space Complexity:
        1. T.C -> O(n) Stack Space is used during recursive calls
 */
 auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 };
class Solution {
public:
    bool isValidNode(TreeNode* root, long long int minValue, long long int maxValue){
        if(!root){
            return true;
        }
        if(root -> val >= maxValue || root -> val <= minValue){
            return false;
        }
        return isValidNode(root -> left, minValue, root -> val) && isValidNode(root -> right, root -> val, maxValue);
    }
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return isValidNode(root, min, max);
    }
};
// @lc code=end

