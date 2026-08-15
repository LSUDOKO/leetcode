class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int all=0;
        int count0=0;
        for (int i=0;i<n;i++){
            if (nums[i]==0)count0++;
            all^=nums[i];
        }
        if (count0==n){
            return 0;
        }
        if (all==0){
            return n-1;
        }
        else{
            return n;
        }
    }
};