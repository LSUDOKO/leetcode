class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int  start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        for (int i=start;i<end;i++){
            ans.push_back(i);
        }
        return ans;
    }
};