class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int maxi=1000000;
        vector<int>freq(maxi+2,0);
        vector<int>ans;
        for (int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for (int i:nums){
            if (freq[i]==1 && (i==0 || freq[i-1]==0) && freq[i+1]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};