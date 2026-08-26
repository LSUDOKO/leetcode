class Solution {
public:
    bool dfs(vector<vector<int>>&adj,int source,int destination,vector<bool>&check){
        if (source==destination){
            return true;
        }
        check[source]=true;
        for (int v: adj[source]){
            if(!check[v]){
                if (dfs(adj,v,destination,check)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for (int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>check(n,false);
        return dfs(adj,source,destination,check);
    }
};