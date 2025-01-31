class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pr=1,suf=1;
        int ans=INT_MIN;
        for (int i=0;i<nums.size();i++){
            if (pr==0) pr=1;
            if (suf==0) suf=1;
            pr*=nums[i];
            suf*=nums[nums.size()-i-1];
            ans=max(ans,max(pr,suf));
        }
        return ans;
    }
};