class Solution {
    public List<List<Integer>> subsets;
    public int[] nums;
    public List<List<Integer>> subsets(int[] nums) {
        subsets = new ArrayList<>();
        this.nums = nums;
        
        List<Integer> subset = new ArrayList<>();
        backtrack(0, subset);
        return this.subsets;
    }
    
    public void backtrack(int i, List<Integer> subset) {
        if (i >= nums.length) {
            List<Integer> ans = new ArrayList<>();
            for(int num: subset) {
                ans.add(num);
            }
            subsets.add(ans);
        }
        else {
            
            backtrack(i + 1, subset);
            
            subset.add(nums[i]);
            backtrack(i + 1, subset);
            subset.remove(subset.size() - 1);
        }
    }
}