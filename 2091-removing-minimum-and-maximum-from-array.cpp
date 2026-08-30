class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int mini=0;
        for (int i=0;i<n;i++){
            if(nums[i]>nums[maxi]){
                maxi=i;
            }
            if (nums[i]<nums[mini]){
                mini=i;
            }
        }
        int left=min(maxi,mini);
        int right=max(mini,maxi);
        int d1=right+1;
        int d2=n-left;
        int d3=left+1+n-right;
        return min(d1,min(d2,d3));
    }
};