class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>a,vector<int>b){
            return a[1]>b[1];
        });
        int ans=0;
        for (auto it:boxTypes){
            if (truckSize>=it[0]){
                ans+=it[0]*it[1];
                truckSize-=it[0];
            }
            else{
                ans+=truckSize*it[1];
                break;
            }
        }
        return ans;
    }
};