class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        vector<int> vec;
        vec.push_back(left);
        vec.push_back(right);
        return vec;
    }
    
    int findLeft(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        int ans = -1;
        
        while (start <= end) {
            int mid = (start + end)/2;
            if (arr[mid] < target) {
                start = mid + 1;
            }
            else if (arr[mid] > target) {
                end = mid - 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    int findRight(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        int ans = -1;
        
        while (start <= end) {
            int mid = (start + end)/2;
            if (arr[mid] < target) {
                start = mid + 1;
            }
            else if (arr[mid] > target) {
                end = mid - 1;
            }
            else {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
};