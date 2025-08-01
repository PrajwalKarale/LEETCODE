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
class Solution {
    public int solve(TreeNode root, int current){
        if(root == null){
            return 0;
        }
        current = (current * 10) + root.val;
        if(root.left == null && root.right == null){
            return current;
        }

        int left = solve(root.left, current);
        int right = solve(root.right, current);
        return left + right;
    }
    public int sumNumbers(TreeNode root) {
        int result = 0;
        result = solve(root, 0);
        return result;
    }
}
