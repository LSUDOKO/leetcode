class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for (int i=0;i<n;i++){
            unordered_set<int>st;
            for (int j=i;j<n;j++){
                st.insert(nums[j]);
                int dis=st.size();
                ans+=dis*dis;
            }
            
        }
        return ans;
    }
};