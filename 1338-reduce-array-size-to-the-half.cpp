class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        for (int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for (auto [ele,freq]:mp){
            pq.push({freq,ele});
        }
        int check=0;
        int count=0;
        while(check<n/2){
            auto [freq,ele]=pq.top();
            check+=freq;
            pq.pop();
            count++;
        }
        return count;

    }
};