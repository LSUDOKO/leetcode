class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>>pq;
        for (int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        vector<string>ans(n);
        int rank=1;
        while(!pq.empty()){
            auto [sc,index]=pq.top();
            pq.pop();
            if (rank==1){
                ans[index]="Gold Medal";
            }
            else if (rank==2){
                ans[index]="Silver Medal";
            }
            else if (rank==3){
                ans[index]="Bronze Medal";
            }
            else {
                ans[index]=to_string(rank);
            }
            rank++;
        }
        return ans;
    }
};