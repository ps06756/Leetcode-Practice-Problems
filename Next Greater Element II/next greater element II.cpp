class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;
        vector<int> ans(nums.size(), -1);
        stack.push(0);
        
        for(int i = 1; i < nums.size(); i++) {
            int current = nums[i];
            while (stack.size() > 0 && nums[stack.top()] < current) {
                ans[stack.top()] = current;
                stack.pop();
            }
            stack.push(i);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            while (stack.size() > 0 && nums[stack.top()] < current) {
                ans[stack.top()] = current;
                stack.pop();
            }
        }
        
        return ans;
    }
};