class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int sum = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp.put(sum, i);
        }
        if (sum < x)
            return -1;
        int restSum = sum - x;
        int longest = Integer.MIN_VALUE;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.containsKey(sum - restSum)) {
                longest = Math.max(longest, i - mp.get(sum - restSum));
            }
        }
        return longest == Integer.MIN_VALUE ? -1 : n - longest;
    }
}