class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> de = new LinkedList<Integer>();
        List<Integer> answers = new ArrayList<>();
        int n = nums.length;
        de.offer(0);
        for(int i = 1; i < k; i++) {
            while (de.size() > 0 && nums[de.peekLast()] < nums[i]) {
                de.removeLast();
            }
            de.offerLast(i);
        }
        answers.add(nums[de.peek()]);
        
        for(int j = k; j < n; j++) {
            int startingPoint = j - k + 1;
            while (de.size() > 0 && de.peek() < j - k + 1) {
                de.removeFirst();
            }
            while (de.size() > 0 && nums[de.peekLast()] < nums[j]) {
                de.removeLast();
            }
            de.offerLast(j);
            answers.add(nums[de.peek()]);
        }
        
        int[] ansArray = new int[answers.size()];
        for(int i = 0; i < answers.size(); i++) {
            ansArray[i] = answers.get(i);
        }
        return ansArray;
    }
}