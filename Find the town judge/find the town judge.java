class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] outdegree = new int[n + 1];
        int[] indegree = new int[n + 1];
        Arrays.fill(outdegree, 0);
        Arrays.fill(indegree, 0);
        
        for(int i = 0; i < trust.length; i++) {
            int[] rel = trust[i];
            int from = rel[0];
            int to = rel[1];
            
            indegree[to]++;
            outdegree[from]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
}