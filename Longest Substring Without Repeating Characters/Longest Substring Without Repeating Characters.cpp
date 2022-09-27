class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int fp = 0, sp = 0, n = s.length();
        
        while (sp < n) {
            mp[s[sp]]++;
            
            while (fp < sp && !isValid(mp)) {
                mp[s[fp]]--;
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
    
    
    bool isValid(unordered_map<char, int>& mp) {
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > 1) {
                return false;
            }
        }
        return true;
    }
};