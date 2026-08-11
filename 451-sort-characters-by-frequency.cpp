class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>store;
        for (int i=0;i<s.size();i++){
            store[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for (auto [c,freq]:store){
            pq.push({freq,c});
        }
        string ans;
        while(!pq.empty()){
            auto [freq,ch]=pq.top();
            pq.pop();
            for (int i=0;i<freq;i++){
                ans+=ch;
            }
        }
        return ans;
    }
};