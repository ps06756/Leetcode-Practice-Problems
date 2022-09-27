class Solution {
    public int maxSubArray(int[] nums) {
        int maxSoFar = nums[0];
        int currentSum = nums[0];
        
        for(int i = 1; i < nums.length; i++) {
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
}