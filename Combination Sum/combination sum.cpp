class Solution {
public:
    vector<vector<int>> answer;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        f(0, target, combination, candidates);
        return answer;
    }
    
    void f(int i, int rem, vector<int>& combination, vector<int>& candidates) {
        if (i == candidates.size()) {
            if (rem == 0) {
                vector<int> combi;
                for(int i = 0; i < combination.size(); i++) {
                    combi.push_back(combination[i]);
                }
                answer.push_back(combi);
            }
        }
        else {
            int maxTimes = rem/candidates[i];
            for(int k = 0; k <= maxTimes; k++) {
                int newTarget = rem;
                for(int j = 0; j < k; j++) {
                    combination.push_back(candidates[i]);
                    newTarget -= candidates[i];
                }
                f(i + 1, newTarget, combination, candidates);
                for(int j = 0; j < k; j++) {
                    combination.pop_back();
                }
            }
        }
    }
};