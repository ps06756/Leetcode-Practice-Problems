class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for(String str: strs) {
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String key = String.valueOf(arr);
            if (!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }
            map.get(key).add(str);
        }
        
        List<List<String>> ans = new ArrayList<>();
        
        for(String key: map.keySet()) {
            ans.add(map.get(key));
        }
        
        return ans;
    
    }
}