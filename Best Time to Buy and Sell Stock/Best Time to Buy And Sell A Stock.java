class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int minimumSoFar = prices[0];
        for(int i = 1; i < prices.length; i++) {
            int currentProfit = prices[i] - minimumSoFar;
            if (currentProfit > ans) {
                ans = currentProfit;
            }
            minimumSoFar = Math.min(minimumSoFar, prices[i]);
        }
        
        return ans;
    }
}