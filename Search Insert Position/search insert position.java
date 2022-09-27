class Solution {
    public int searchInsert(int[] nums, int target) {
        int ans = 0;
        int st = 0, end = nums.length-1;
        
        while(st<=end) {
            int mid = st + (end - st)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                st = mid + 1;
                ans = st;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
}