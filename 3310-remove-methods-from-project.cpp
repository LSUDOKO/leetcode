class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<int>suspicous(n,false);

        for (auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>que;
        que.push(k);
        suspicous[k]=true;
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            for (int &ngbr:adj[curr]){
                indegree[ngbr]--;
                if (!suspicous[ngbr]){
                    que.push(ngbr);
                    suspicous[ngbr]=true;
                }
            }
        }


        vector<int>result;
        bool cannot_remove=false;
        for (int i=0;i<n;i++){
            if (suspicous[i] && indegree[i]>0){
                cannot_remove=true;
                break;
            }
            if (!suspicous[i]){
                result.push_back(i);
            }
        }

        if (cannot_remove){
            vector<int>vec(n);
            for (int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return result;
    }
};