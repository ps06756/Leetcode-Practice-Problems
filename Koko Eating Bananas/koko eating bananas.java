class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int start = 1;
        int end = piles[0];
        for(int i = 1; i < piles.length; i++) {
            end = Math.max(end, piles[i]);
        }
        
        int ans = -1;
        while (start <= end) {
            int mid = (start + end)/2;
            if (isPossible(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
    
    public boolean isPossible(int[] piles, int h, int speed) {
        int noOfHours = 0;
        for(int i = 0; i < piles.length; i++) {
            noOfHours += Math.ceil((piles[i] + 0.0)/speed);
        }
        return noOfHours <= h;
    }
}