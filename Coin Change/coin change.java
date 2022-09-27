class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        return f(amount, coins, dp);
    }
    
    int f(int i, int[] coins, int[] dp) {
        if (i <= 0) {
            return 0;
        }
        else {
            int ans = -1;
            if (dp[i] != 0) {
                return dp[i];
            }
            for(int coin: coins) {
                if (coin <= i) {
                    int val = f(i - coin, coins, dp);
                    if (val != -1 && (ans == -1 || val + 1 < ans)) {
                        ans = val + 1;
                    }
                }
            }
            dp[i] = ans;
            return ans;
        }
    }
}