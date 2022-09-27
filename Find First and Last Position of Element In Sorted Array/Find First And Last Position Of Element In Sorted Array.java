class Solution {
    public int[] searchRange(int[] nums, int target) {
        int leftIndex = findLeft(nums, target);
        int rightIndex = findRight(nums, target);
        
        int[] ans = new int[2];
        ans[0] = leftIndex;
        ans[1] = rightIndex;
        
        return ans;
    }
    
    int findLeft(int[] nums, int target) {
        
        int start = 0, end = nums.length - 1;
        int ans = -1;
        
        while (start <= end) {
            int mid = (start + end)/2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    int findRight(int[] nums, int target) {
        
        int start = 0, end = nums.length - 1;
        int ans = -1;
        
        while (start <= end) {
            int mid = (start + end)/2;
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                ans = mid;
                start = mid + 1;
            }
        }
        
        return ans;
    }
}