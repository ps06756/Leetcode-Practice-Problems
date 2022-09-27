class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};