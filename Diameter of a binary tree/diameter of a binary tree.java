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
    class Pair {
        public int first;
        public int second;
        public Pair(int x, int y) {
            first = x;
            second = y;
        }
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        Pair p = f(root);
        return p.first;
    }
    
    public Pair f(TreeNode node) {
        if (node == null) {
            return new Pair(0, 0);
        }
        else {
            Pair left = f(node.left);
            Pair right = f(node.right);
            
            int height = Math.max(left.second, right.second) + 1;
            int diameter = Math.max(Math.max(left.first, right.first), left.second + right.second);
            return new Pair(diameter, height);
        }
    }
}