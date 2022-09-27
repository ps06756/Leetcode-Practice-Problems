class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] < b[0]) {
                return -1;
            }
            else if (a[0] > b[0]) {
                return 1;
            }
            else {
                return a[1] - b[1];
            }
        });
        
        List<int[]> answer = new ArrayList<>();
        answer.add(intervals[0]);
        
        for(int i = 1; i < intervals.length; i++) {
            int[] currentInterval = intervals[i];
            int[] lastInterval = answer.get(answer.size() - 1);
            if (currentInterval[0] <= lastInterval[1]) {
                int[] newInterval = new int[] { Math.min(lastInterval[0], currentInterval[0]), Math.max(lastInterval[1], currentInterval[1])};
                answer.remove(answer.size() - 1);
                answer.add(newInterval);
            }
            else {
                answer.add(currentInterval);
            }
        }
        
        int[][] finalAnswer = new int[answer.size()][2];
        for(int i = 0; i < answer.size(); i++) {
            finalAnswer[i][0] = answer.get(i)[0];
            finalAnswer[i][1] = answer.get(i)[1];
        }
        
        return finalAnswer;
    }
}