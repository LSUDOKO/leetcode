class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n);
        vector<int>mini(n);
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        for (int i=0;i<n;i++){
            if(maximum>nums[i]){
                maxi[i]=maximum;

            }
            else{
                maximum=nums[i];
                maxi[i]=maximum;
            }
        }
        for (int i=n-1;i>=0;i--){
            if(minimum<nums[i]){
                mini[i]=minimum;

            }
            else{
                minimum=nums[i];
                mini[i]=minimum;
            }
        }

        for (int i=0;i<n;i++){
            if (maxi[i]-mini[i]<=k){
                return i;
            }
        }
        return -1;
    }
};