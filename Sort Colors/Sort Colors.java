class Solution {
public int[] sortColors(int[] nums) {

        int[] hash = new int[3];
        Arrays.fill(hash, 0);


        int i = 0;
        while (i < nums.length) {
            if (nums[i] == 0) hash[0] = hash[0] + 1;
            if (nums[i] == 1) hash[1] = hash[1] + 1;
            if (nums[i] == 2) hash[2] = hash[2] + 1;

            i++;
        }
        i = 0;
        int k = 0;
        while (i < hash.length) {
            int j = hash[i];
            while (j > 0) {
                nums[k] = i;
                k++;
                j--;
            }
            i++;
        }
        return nums;
    }
}