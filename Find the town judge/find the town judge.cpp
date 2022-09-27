class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n + 1, 0);
        vector<int> in(n + 1, 0);
        
        for(int i = 0; i < trust.size(); i++) {
            vector<int> vec = trust[i];
            int from = vec[0];
            int to = vec[1];
            in[to]++;
            out[from]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if (out[i] == 0 && in[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};