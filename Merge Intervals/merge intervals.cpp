class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> currentInterval = intervals[i];
            vector<int> lastInterval = answer[answer.size() - 1];
            if (lastInterval[1] >= currentInterval[0]) {
                vector<int> newInterval = { lastInterval[0], max(lastInterval[1], currentInterval[1])};
                answer.pop_back();
                answer.push_back(newInterval);
            }
            else {
                answer.push_back(currentInterval);
            }
        }
        
        return answer;
    }
};