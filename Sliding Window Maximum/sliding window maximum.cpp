class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answers;
        deque<int> de;
        de.push_back(0);
        for(int i = 1; i < k; i++) {
            while (de.size() > 0 && nums[de.back()] < nums[i]) {
                de.pop_back();
            }
            de.push_back(i);
        }
        answers.push_back(nums[de.front()]);
        
        for(int j = k; j < nums.size(); j++) {
            int startingPoint = j - k + 1;
            while (de.size() > 0 && de.front() < startingPoint) {
                de.pop_front();
            }
            while (de.size() > 0 && nums[de.back()] < nums[j]) {
                de.pop_back();
            }
            de.push_back(j);
            answers.push_back(nums[de.front()]);
        }
        
        return answers;
    }
};