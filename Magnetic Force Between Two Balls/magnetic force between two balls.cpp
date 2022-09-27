class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        
        int start = 1;
        int end = position[n-1] - position[0];
        
        int ans = 1;
        while (start <= end) {
            int mid = (start + end)/2;
            if (isDistancePossible(position, m, mid)) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
    
    bool isDistancePossible(vector<int>& position, int m, int dist) {
        int noOfBallsPlaced = 1;
        int lastPosition = position[0];
        
        for(int i = 1; i < position.size() && noOfBallsPlaced < m; i++) {
            if (position[i] >= lastPosition + dist) {
                noOfBallsPlaced++;
                lastPosition = position[i];
            }
        }
        
        if (noOfBallsPlaced < m) return false;
        else return true;
    }
    
    
};