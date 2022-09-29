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
        public int level;
        public TreeNode node;
        
        public Pair(int level, TreeNode node) {
            this.level = level;
            this.node = node;
        }
    }
    
    public int maxLevelSum(TreeNode root) {
        Map<Integer, Integer> map = new HashMap<>();
        Queue<Pair> q = new LinkedList<>();
        
        q.add(new Pair(1, root));
        while (!q.isEmpty()) {
            Pair top = q.poll();
            if (!map.containsKey(top.level)) {
                map.put(top.level, 0);
            }
            map.put(top.level, map.get(top.level) + top.node.val);
            if (top.node.left != null) {
                q.add(new Pair(top.level + 1, top.node.left));
            }
            if (top.node.right != null) {
                q.add(new Pair(top.level + 1, top.node.right));
            }  
        }
        
        int ans = 1;
        for(Integer level: map.keySet()) {
            if (map.get(level) > map.get(ans)) {
                ans = level;
            }
        }
        
        return ans;
    }
}