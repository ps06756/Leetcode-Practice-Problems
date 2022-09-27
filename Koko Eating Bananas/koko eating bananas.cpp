class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = piles[0];
        for(int i = 1; i < piles.size(); i++) {
            end = max(end, piles[i]);
        }
        
        int ans = end;
        
        while (start <= end) {
            int mid = (start + end)/2;
            if (countHours(piles, mid) > (long) h) {
                start = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    long countHours(vector<int>& piles, int speed) {
        long noOfHours = 0;
        for(int i = 0; i < piles.size(); i++) {
            noOfHours += findCeil(piles[i], speed);
        }
        return noOfHours;
    }
    
    long findCeil(int a, int b) {
        if (a%b == 0) {
            return a/b;
        }
        else {
            return (a/b) + 1;
        }
    }
    
};