class Solution {
public:
    double gain(int u,int l){
        return (double)(u+1)/(l+1)-(double)u/l;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<tuple<double,int,int>>pq;
        for (int i=0;i<n;i++){
            int p=classes[i][0];
            int t=classes[i][1];
            pq.push({gain(p,t),p,t});
        }
        while(extraStudents--){
            auto [g,p,t]=pq.top();
            pq.pop();
            p++;
            t++;
            pq.push({gain(p,t),p,t});
        }
        double ans=0;
        while(!pq.empty()){
            auto [g,p,t]=pq.top();
            pq.pop();
            ans+=(double)p/t;

        }
        return ans/classes.size();

    }
};