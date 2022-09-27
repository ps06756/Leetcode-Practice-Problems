class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> ht;
        return f(0, target, nums, ht);
    }
    
    int f(int i, int ct, vector<int>& nums, map<pair<int, int>, int>& ht) {
        if (i < nums.size() - 1) {
            pair<int, int> key = make_pair(i, ct);
            if (ht.find(key) == ht.end()) {
                ht[key] = f(i + 1, ct - nums[i], nums, ht) + f(i + 1, ct + nums[i], nums, ht);
            }
            return ht[key];
        }
        else {
            if (ct == 0 && nums[i] == 0) {
                return 2;
            }
            else if (abs(ct) == abs(nums[i])) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
};