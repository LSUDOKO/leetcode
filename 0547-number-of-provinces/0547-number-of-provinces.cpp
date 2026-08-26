class Solution {
public:
    void dfs(int city,vector<vector<int>>&isConnected,vector<bool>&vis){
        if (vis[city]) return ;
        vis[city]=true;
        for (int x=0;x<isConnected.size();x++){
            if (isConnected[city][x]==1 && !vis[x]){
                dfs(x,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        vector<bool>vis(n,false);
        int prov=0;
        for (int i=0;i<n;i++){
            if(!vis[i]){
                prov++;
                dfs(i,isConnected,vis);
            }
        }
        return prov;
    }
};