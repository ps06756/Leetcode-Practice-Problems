class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumSoFar = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            int currentProfit = prices[i] - minimumSoFar;
            ans = max(ans, currentProfit);
            minimumSoFar = min(minimumSoFar, prices[i]);
        }
        return ans;
    }
};