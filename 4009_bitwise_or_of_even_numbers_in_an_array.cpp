class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans=ans|nums[i];
            }
        }
        return ans;
    }
};