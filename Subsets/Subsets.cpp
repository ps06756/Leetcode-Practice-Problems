class Solution {
public:
    vector<vector<int>> powerSet;
    vector<int> subset;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return powerSet;
    }
    
    void backtrack(int i, vector<int>& nums) {
        if (i == nums.size()) {
            vector<int> ans;
            for(int i = 0; i < subset.size(); i++) {
                ans.push_back(subset[i]);
            }
            powerSet.push_back(ans);
        }
        else {
            backtrack(i + 1, nums);
            
            subset.push_back(nums[i]);
            backtrack(i + 1, nums);
            subset.pop_back();
        }
    }
};