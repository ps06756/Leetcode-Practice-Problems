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
    private TreeNode firstParent, secondParent;
    private int firstLevel, secondLevel;
    
    public boolean isCousins(TreeNode root, int x, int y) {
        preOrder(root, 0, null, x, y);
        return (firstLevel == secondLevel && firstParent != secondParent);
    }
    
    public void preOrder(TreeNode node, int level, TreeNode parent, int x, int y) {
        if (node != null) {
            if (node.val == x) {
                firstParent = parent;
                firstLevel = level;
            }
            if (node.val == y) {
                secondParent = parent;
                secondLevel = level;
            }
            
            if (node.left != null) {
                preOrder(node.left, level + 1, node, x, y);
            }
            if (node.right != null) {
                preOrder(node.right, level + 1, node, x, y);
            }
        }
    }
    
}