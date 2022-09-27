class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(2);
        for(int i = 0; i < 2; i++) {
            dp[i] = vector<int>(nums.size(), -1);
        }
        
        return f(0, 1, dp, nums);
        
    }
    
    int f(int i, int canRob, vector<vector<int>>& dp, vector<int>& nums) {
        if (i == nums.size() - 1) {
            if (canRob == 1) {
                return nums[i];
            }
            else {
                return 0;
            }
        }
        else {
            if (dp[canRob][i] != -1) {
                return dp[canRob][i];
            }
            if (canRob == 1) {
                dp[canRob][i] = max(nums[i] + f(i + 1, 0, dp, nums), f(i + 1, 1, dp, nums));
            }
            else {
                dp[canRob][i] = f(i + 1, 1, dp, nums);
            }
            return dp[canRob][i];
        }
    }
};