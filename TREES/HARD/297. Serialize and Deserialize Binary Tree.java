/*
 * @lc app=leetcode id=297 lang=java
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder data = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        if(root == null){
            return "";
        }
        q.add(root);
        while(!q.isEmpty()){
            TreeNode node = q.poll();
            if(node == null){
                data.append("null ");
                continue;
            }
            data.append(node.val + " ");
            q.add(node.left);
            q.add(node.right);
        }
        return data.toString();
    }

    // Decodes your encoded data to tree.
public TreeNode deserialize(String data) {
    if (data.isEmpty()) {
        return null;
    }
    String[] values = data.split(" ");
    Queue<TreeNode> q = new LinkedList<>();
    TreeNode root = new TreeNode(Integer.parseInt(values[0]));
    q.add(root);
    int i = 1;
    while (!q.isEmpty() && i < values.length) {
        TreeNode parent = q.poll();
        // Left child
        if (i < values.length && !values[i].equals("null")) {
            parent.left = new TreeNode(Integer.parseInt(values[i]));
            q.add(parent.left);
        }
        i++;
        // Right child
        if (i < values.length && !values[i].equals("null")) {
            parent.right = new TreeNode(Integer.parseInt(values[i]));
            q.add(parent.right);
        }
        i++;
    }
    return root;
}
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
// @lc code=end
