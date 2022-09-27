class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        Map<String, Integer> map = new HashMap<>();
        return f(0, target, nums, map);
    }
    
    public int f(int i, int requiredSum, int[] nums, Map<String, Integer> map) {
        if (i == nums.length - 1) {
            if (requiredSum == 0 && nums[i] == 0) {
                return 2;
            }
            else if (requiredSum != 0 && Math.abs(requiredSum) == Math.abs(nums[i])) {
                return 1;
            }
            return 0;
        }
        else {
            String key = i + ":" + requiredSum;
            if (!map.containsKey(key)) {
                int ans = f(i + 1, requiredSum - nums[i], nums, map) + f(i + 1, requiredSum + nums[i], nums, map);
                map.put(key, ans);
            }
            return map.get(key);
        }
    }
}