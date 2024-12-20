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
            1. Performing Level Order Traversal
        Time Complexity:
            1. T.C -> O(n)
            2. n is the total number of nodes present. Since we are visiting each and every node present in the tree.
        Space Complexity:
            1. S.C -> O(n)
            2. n is the total number of nodes present in the tree. Since we are using queue data structure
    */
    auto fastIO = [](){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    };
    class Solution {
    public:
        TreeNode* reverseOddLevels(TreeNode* root) {
            if(!root){
                return nullptr;
            }
            queue<TreeNode*>q;
            q.push(root);
            bool isOddLevel = false;
            while(!q.empty()){
                int qSize = q.size();
                vector<TreeNode*>levelNodes;
                for(int i = 0; i < qSize; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    levelNodes.push_back(node);
                    if(node -> left){
                        q.push(node -> left);
                    }
                    if(node -> right){
                        q.push(node -> right);
                    }
                }
                if(isOddLevel){
                    int left = 0;
                    int right = levelNodes.size() - 1;
                    while(left < right){
                        swap(levelNodes[left] -> val, levelNodes[right] -> val);
                        left++;
                        right--;
                    }
                }
                isOddLevel = !isOddLevel;
            }
            return root;
        }
    };
