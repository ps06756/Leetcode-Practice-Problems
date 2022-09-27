class Solution {
    public boolean canJump(int[] nums) {
        int maxReachable = nums[0];
        int i = 1;
        while (i < nums.length && maxReachable >= i) {
            if (i + nums[i] > maxReachable) {
                maxReachable = i + nums[i];
            }
            i++;
        }
        
        if (maxReachable >= nums.length - 1) {
            return true;
        }
        else {
            return false;
        }
    }
}