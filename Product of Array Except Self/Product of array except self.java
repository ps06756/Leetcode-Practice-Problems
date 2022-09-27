class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        int n = nums.length;
        
        left[0] = 1;
        for(int i = 1; i < nums.length; i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        
        right[n-1] =  1;
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        
        int[] output = new int[n];
        
        for(int i = 0; i < n; i++) {
            output[i] = left[i]*right[i];
        }
        
        return output;
    }
}