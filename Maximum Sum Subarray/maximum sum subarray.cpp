class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int currentSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if (currentSum < 0) {
                currentSum = 0;
            }
            currentSum = currentSum + nums[i];
            if (currentSum > maxSoFar) {
                maxSoFar = currentSum;
            }
        }
        
        return maxSoFar;
    }
};