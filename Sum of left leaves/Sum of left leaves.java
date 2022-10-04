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
    private int sum = 0;
    
    public int sumOfLeftLeaves(TreeNode root) {
        preOrder(root, false);
        return this.sum;
    }
    
    public void preOrder(TreeNode node, boolean leftChild) {
        if (node != null) {
            if (node.left == null && node.right == null && leftChild == true){ 
                this.sum += node.val;
            }
            if (node.left != null) {
                preOrder(node.left, true);
            }
            if (node.right != null) {
                preOrder(node.right, false);
            }
        }
    }
}
