class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // for (int i=0;i)
        sort(nums.begin(),nums.end());
        int total_sum=0;
        for (int i=0;i<nums.size()-2;i++){
            int maxi=max(nums[i],max(nums[i+1],nums[i+2]));
            int sum=nums[i]+nums[i+1]+nums[i+2];
            int left =sum-maxi;
            if (left> maxi){
                total_sum=max(sum,total_sum);
            }
        }
        return total_sum;
    }
};