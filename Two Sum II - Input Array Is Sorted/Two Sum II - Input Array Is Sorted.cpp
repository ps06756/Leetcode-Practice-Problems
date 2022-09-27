class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int f = 0, s = numbers.size() - 1;
        vector<int> ans;
        
        while (f < s) {
            int sum = numbers[f] + numbers[s];
            if (sum < target) {
                f++;
            }
            else if (sum > target) {
                s--;
            }
            else {
                ans.push_back(f + 1);
                ans.push_back(s + 1);
                break;
            }
        }
        
        return ans;
    }
};