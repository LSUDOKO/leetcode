class Solution {
public:
    int findGCD(vector<int>& nums) {
         sort(nums.begin(), nums.end());
       int n = nums.size()-1;

       if(nums[0] == 0) return nums[n];

       if(nums[n] == 0) return nums[0];

       while(nums[0] > 0 && nums[n] > 0){

           if(nums[0] > nums[n]) nums[0] = nums[0] - nums[n];

           else nums[n] = nums[n] - nums[0];
       } 

       return nums[0]== 0 ? nums[n] : nums[0];
    }
};