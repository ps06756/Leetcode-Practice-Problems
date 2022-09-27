class Solution {
public:
    void sortColors(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
        int i = 0;
        
        while (i <= right) {
            if (arr[i] == 0) {
                int temp = arr[i];
                arr[i] = arr[left];
                arr[left] = temp;
                i++;
                left++;
            }
            else if (arr[i] == 2) {
                int temp = arr[i];
                arr[i] = arr[right];
                arr[right] = temp;
                right--;
            }
            else {
                i++;
            }
        }
    }
};