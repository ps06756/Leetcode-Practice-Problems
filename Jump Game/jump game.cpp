class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = nums[0];
        
        int i = 1;
        while (i < nums.size() && maxReachable >= i) {
            if (i + nums[i] > maxReachable) {
                maxReachable = i + nums[i];
            }
            i++;
        }
        
        if (maxReachable >= nums.size() - 1) {
            return true;
        }
        else {
            return false;
        }
    }
};