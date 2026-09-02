class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>adj(n);
        for (int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
        vector<int>result(n,0);
        for (int start=0;start<n;start++){
            vector<int>dis(n,-1);
            queue<int>q;
            q.push(start);
            dis[start]=0;
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for (int nei:adj[front]){
                    if(dis[nei]==-1){
                        dis[nei]=dis[front]+1;
                        q.push(nei);
                    }
                }
            }
            for (int i=0;i<n;i++){
                if(i!=start){
                    result[dis[i]-1]++;
                }
            }
        }
        return result;
    }
};