class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int[] ans = new int[nums.length];
        
        for(int i = 1; i < nums.length; i++) {
            int current = nums[i];
            while (stack.size() > 0 && nums[stack.peek()] < current) {
                ans[stack.peek()] = current;
                stack.pop();
            }
            stack.push(i);
        }
        
        for(int i = 0; i < nums.length; i++) {
            int current = nums[i];
            while (stack.size() > 0 && nums[stack.peek()] < current) {
                ans[stack.peek()] = current;
                stack.pop();
            }
        }
        
        while (stack.size() > 0) {
            ans[stack.peek()] = -1;
            stack.pop();
        }
        
        return ans;
    }
}