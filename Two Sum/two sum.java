class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> ht = new HashMap<>();
        int[] ans = new int[2];
        for(int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (ht.containsKey(complement)) {
                ans[0] = ht.get(complement);
                ans[1] = i;
                break;
            }
            ht.put(nums[i], i);
        }
        
        return ans;
    }
}