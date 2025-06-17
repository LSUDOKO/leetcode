class Solution {
public:
    // Helper function to check if we can split into <= k subarrays with maxSumAllowed
    bool canSplit(vector<int>& nums, int k, int maxSumAllowed) {
        int count = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSumAllowed) {
                count++;
                currentSum = num;
                if (count > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};