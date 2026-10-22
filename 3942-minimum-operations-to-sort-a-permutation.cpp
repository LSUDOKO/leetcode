class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int asc_count = 0;
        int dsc_count = 0;

        for(int i = 1; i < n; i++) {
            asc_count += (nums[i] == (nums[i-1]+1)%n);
            dsc_count += (nums[i-1] == (nums[i]+1)%n);
        }

        if(asc_count == n-1 && nums[0] == 0) {
            return 0;
        }

        if(asc_count == n-1) {
            int leftRot  = n - nums[0];
            int rightRot = 1 + (nums.back() + 1) + 1;
            return min(leftRot, rightRot);
        }

        if(dsc_count == n-1) {
            int leftRot = n-nums.back() + 1;
            int rightRot = (nums[0]+1)%n + 1;

            return min(leftRot, rightRot);
        }

        return -1;
    }
};