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
    List<List<Integer>> answer = new ArrayList<>();
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> path = new ArrayList<>();
        int sumTillParent = 0;
        preOrder(root, sumTillParent, path, targetSum);
        return this.answer;
    }
    
    public void preOrder(TreeNode node, int sumTillParent, List<Integer> pathTillParent, int targetSum) {
        if (node != null) {
            int sumTillMe = sumTillParent + node.val;
            pathTillParent.add(node.val);
                
            if (node.left == null && node.right == null && sumTillMe == targetSum) {
                List<Integer> currentPath = new ArrayList<>();
                for(Integer val: pathTillParent) currentPath.add(val);
                answer.add(currentPath);
            }
            
            if (node.left != null) {
                preOrder(node.left, sumTillMe, pathTillParent, targetSum);
            }
            if (node.right != null) {
                preOrder(node.right, sumTillMe, pathTillParent, targetSum);
            }
            pathTillParent.remove(pathTillParent.size() - 1);
        }
    }
}