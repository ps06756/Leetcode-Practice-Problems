class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int currentProduct = 1;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != 0) {
                currentProduct = currentProduct * nums[i];
                if (currentProduct > ans) {
                    ans = currentProduct;
                }
            }
            else {
                currentProduct = 1;
            }
        }
        
        currentProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != 0) {
                currentProduct = currentProduct * nums[i];
                if (currentProduct > ans) {
                    ans = currentProduct;
                }
            }
            else {
                currentProduct = 1;
            }
        }
        
        return ans;
    }
};