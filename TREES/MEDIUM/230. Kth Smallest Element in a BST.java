/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
/*
    Logic:
        1. Use Inorder traversal so that we get in ascending order.
    Time Complexity:

    Space Complexity:
        1. We are using List as an auxiliary space.
        2. S.C -> O(n)
*/
class Solution {
    private List<Integer> inOrderList = new ArrayList<>();
    public void inOrder(TreeNode root, List<Integer>inOrderList){
        if(root == null){
            return;
        }
        inOrder(root.left, inOrderList);
        inOrderList.add(root.val);
        inOrder(root.right, inOrderList);
    }
    public int kthSmallest(TreeNode root, int k) {
        inOrder(root, inOrderList);
        return inOrderList.get(k - 1);    
    }
}
