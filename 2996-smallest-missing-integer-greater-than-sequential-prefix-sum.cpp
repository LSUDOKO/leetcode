class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int i=1;
        while(i<nums.size() && nums[i]==(nums[i-1]+1)){
            sum+=nums[i];
            i++;
        }
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};