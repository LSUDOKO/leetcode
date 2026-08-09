class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for (int x:stones){
            pq.push(x);
        }
        if (pq.size()==1){
            return pq.top();
        }
        while(pq.size()>1){
            int top=pq.top();
            pq.pop();
            int sectop=pq.top();
            pq.pop();
            if (top!=sectop){
                pq.push(abs(sectop-top));
            }
        }
        if (pq.empty()){
            return 0;
        }
        return pq.top();

    }
};