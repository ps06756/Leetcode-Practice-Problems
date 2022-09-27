class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int fp = 0, sp = 0;
        int n = s.length();
        Map<Character, Integer> mp = new HashMap<>();
        
        while (sp < n) {
            addToMap(mp, s.charAt(sp));
            while (fp < sp && !isValid(mp)) {
                deleteFromMap(mp, s.charAt(fp));
                fp++;
            }
            int length = sp - fp + 1;
            if (length > ans) {
                ans = length;
            }
            sp++;
        }
        
        return ans;
    }
    
    public void addToMap(Map<Character, Integer> mp, char c) {
        if (!mp.containsKey(c)) {
            mp.put(c, 1);
        }
        else {
            mp.put(c, mp.get(c) + 1);
        }
    }
    
    public void deleteFromMap(Map<Character, Integer> mp, char c) {
        mp.put(c, mp.get(c) - 1);
    }
    
    public boolean isValid(Map<Character, Integer> mp) {
        for(char c : mp.keySet()) {
            if (mp.get(c) > 1) {
                return false;
            }
        }
        return true;
    }
}