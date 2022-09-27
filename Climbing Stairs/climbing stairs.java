class Solution {
    public Map<Integer, Integer> map = new HashMap<>();
    
    public int climbStairs(int n) {
        return f(0, n);
    }
    
    public int f(int i, int n) {
        if (i > n) {
            return 0;
        }
        else if (i == n) {
            return 1;
        }
        else {
            if (map.containsKey(i)) {
                return map.get(i);
            }
            else {
                int val = f(i + 1, n) + f(i + 2, n);
                map.put(i, val);
                return val;
            }
            
        }
    }
}