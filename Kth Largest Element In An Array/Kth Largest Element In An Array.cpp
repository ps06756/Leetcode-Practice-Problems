class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(k);
        for(int i = 0; i < k; i++) heap[i] = nums[i];
        
        make_heap(heap.begin(), heap.end(), greater<int>());
        
        for(int i = k; i < nums.size(); i++) {
            if (nums[i] >= heap[0]) {
                heap.push_back(nums[i]);
                push_heap(heap.begin(), heap.end(), greater<int>());
                
                pop_heap(heap.begin(), heap.end(), greater<int>());
                heap.pop_back();
            }
        }
        
        return heap[0];
    }
};