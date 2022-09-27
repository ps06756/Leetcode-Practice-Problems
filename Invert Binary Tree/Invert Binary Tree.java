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
    public TreeNode invertTree(TreeNode root) {
        return invert(root);
    }
    
    public TreeNode invert(TreeNode node) {
        if (node != null) {
            TreeNode left = invert(node.left);
            TreeNode right = invert(node.right);
            
            node.left = right;
            node.right = left;
        }
        return node;
    }
}