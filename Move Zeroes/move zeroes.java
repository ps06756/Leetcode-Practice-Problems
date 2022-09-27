class Solution {
    public void moveZeroes(int[] nums) {
        int i=nums.length;
        for(int ind=0;ind<nums.length;ind++) {
            if(nums[ind]==0) {
                i = ind;
                break;
            } 
            
        }
        
        int j = i+1;
        while(j<nums.length) {
            if(nums[j]!=0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
            j++;
        }
        
    }
}