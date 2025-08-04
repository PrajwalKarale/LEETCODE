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
        Queue<TreeNode> q = new LinkedList<>();
        String values[] = data.split(" ");
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        int n = values.length;
        for(int i = 1; i < n; ++i){
            TreeNode parent = q.poll();
            if(parent == null){
                continue;
            }
            if(!values[i].equals("null")){
                TreeNode node = new TreeNode(Integer.parseInt(values[i]));
                parent.left = node;
                q.add(node);
            }
            if (++i < values.length && !values[i].equals("null")) {
                TreeNode right = new TreeNode(Integer.parseInt(values[i]));
                parent.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
// @lc code=end
