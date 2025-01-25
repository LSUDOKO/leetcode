class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long as=1;
        ans.push_back(as);
        for (int i=0;i<rowIndex;i++){
            as=as*(rowIndex-i);
            as=as/(i+1);
            ans.push_back(as);
        }
        return ans;
    }
};