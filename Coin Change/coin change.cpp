class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        return f(amount, coins, dp);
    }
    
    int f(int i, vector<int>& coins, vector<int>& dp) {
        if (i <= 0) {
            return 0;
        }
        else {
            if (dp[i] != 0) {
                return dp[i];
            }
            else {
                int ans = -1;
                for(int j = 0; j < coins.size(); j++) {
                    if (coins[j] <= i) {
                        int val = f(i - coins[j], coins, dp);
                        if (val != -1) {
                            int currentAns = 1 + val;
                            if (ans == -1 || currentAns < ans) {
                                ans = currentAns;
                            }
                        }
                    }
                }
                dp[i] = ans;
                return ans;
            }
        }
    }
};