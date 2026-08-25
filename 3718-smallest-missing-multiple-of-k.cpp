class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>ans;
        for (int x:nums){
            ans.insert(x);
        }
        int i=1;
        while(true){
            if (ans.count(k*i)){
                i++;
            }
            else{
                break;
            }
        }
        return i*k;
    }
};