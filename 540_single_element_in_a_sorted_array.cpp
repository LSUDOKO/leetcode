class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 0) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n] != nums[n - 1]) return nums[n];
        int low = 1, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || 
                     (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;}
};