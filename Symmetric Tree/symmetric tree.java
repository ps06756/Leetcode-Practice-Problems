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
    public boolean isSymmetric(TreeNode root) {
        return isSym(root.left, root.right);
    }
    
    public boolean isSym(TreeNode f1, TreeNode f2) {
        if (f1 == null && f2 == null) return true;
        if (f1  == null || f2 == null) return false;
        return f1.val == f2.val && isSym(f1.left, f2.right) && isSym(f1.right, f2.left);
    }
}