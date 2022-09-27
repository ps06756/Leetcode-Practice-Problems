class Solution {
    private int[][] dp;
    public int rob(int[] nums) {
        dp = new int[2][nums.length];
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < nums.length; j++) {
                dp[i][j] = -1;
            }
        }
        return f(0, 1, nums);
    }
    
    public int f(int i, int canRob, int[] nums) {
        if (i == nums.length - 1) {
            if (canRob == 0) {
                return 0;
            }
            else {
                return nums[i];
            }
        }
        else {
            if (dp[canRob][i] != -1) {
                return dp[canRob][i];
            }
            if (canRob == 1) {
                dp[canRob][i] = Math.max(nums[i] + f(i + 1, 0, nums), f(i + 1, 1, nums));
            }
            else {
                dp[canRob][i] = f(i + 1, 1, nums);
            }
            return dp[canRob][i];
        }
    }
}