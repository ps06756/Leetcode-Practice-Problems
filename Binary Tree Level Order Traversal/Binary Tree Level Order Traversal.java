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
        public TreeNode node;
        public int level;
        public Pair(TreeNode node, int level) {
            this.node = node;
            this.level = level;
        }
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> answer = new ArrayList<>();
        if (root == null) {
            return answer;
        }
        
        Queue<Pair> q = new LinkedList<Pair>();
        
        q.offer(new Pair(root, 1));
        
        while (q.size() > 0) {
            Pair p = q.peek();
            q.remove();
            
            TreeNode currentNode = p.node;
            int currentLevel = p.level;
            if (answer.size() < currentLevel) {
                answer.add(new ArrayList<>());
            }
            
            answer.get(answer.size() - 1).add(currentNode.val);
            
            if (currentNode.left != null) {
                q.offer(new Pair(currentNode.left, currentLevel + 1));
            }
            
            if (currentNode.right != null) {
                q.offer(new Pair(currentNode.right, currentLevel + 1));
            }
        }
        
        return answer;
    }
}