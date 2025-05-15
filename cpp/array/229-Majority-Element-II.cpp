class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mpp;
        int m=int(nums.size()/3)+1;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if (mpp[nums[i]]==m){
                ans.push_back(nums[i]);
            }
            if (ans.size()==2)
            break;
        }
        return ans;
    }
};