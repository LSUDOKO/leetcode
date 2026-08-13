class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for (int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for (auto [chr,cnt]:mp){
            pq.push({cnt,chr});
        }
        string result;
        while(!pq.empty()){
            auto [cnt,ch]=pq.top();
            pq.pop();
            if (result.size()>=1 && result.back()==ch){
                if (pq.empty()){
                    return "";
                }
                auto [cnt2,ch2]=pq.top();
                pq.pop();
                result+=ch2;
                cnt2--;
                if (cnt2>0){
                    pq.push({cnt2,ch2});
                }
                pq.push({cnt,ch});
            }
            else{
                result+=ch;
                cnt--;
                if (cnt>0){
                    pq.push({cnt,ch});
                }
            }
        }
        return result;
    }
};