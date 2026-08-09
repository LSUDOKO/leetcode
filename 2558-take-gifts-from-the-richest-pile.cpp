class Solution {
public:
    int squareroot(int number){
        return floor(pow(number,0.5));
    }
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=0;
        int n=gifts.size();
        priority_queue<int>pq;
        for (int i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        while(k--){
            int maxi=pq.top();
            int op=squareroot(maxi);
            pq.pop();
            pq.push(op);
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};