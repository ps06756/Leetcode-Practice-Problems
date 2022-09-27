class Solution {
    private String text1, text2;
    private int[][] dp;
    public int longestCommonSubsequence(String text1, String text2) {
        this.text1 = text1;
        this.text2 = text2;
        int n = text1.length();
        int m = text2.length();
        
        this.dp = new int[n][m];
        return lcs(n-1, m-1);
    }
    
    int lcs(int i, int j) {
        if (i == -1 || j == -1) {
            return 0;
        }
        else {
            if (this.dp[i][j] != 0) {
                return this.dp[i][j];
            }
            
            if (text1.charAt(i) == text2.charAt(j)) {
                this.dp[i][j] = lcs(i-1, j-1) + 1;
            }
            else {
                this.dp[i][j] = Math.max(lcs(i-1, j), lcs(i, j-1));
            }
            return this.dp[i][j];
        }
    }
}