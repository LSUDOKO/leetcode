class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if (a>0) pq.push({a,'a'});
        if (b>0) pq.push({b,'b'});
        if (c>0) pq.push({c,'c'});
        string ans;
        while(!pq.empty()){
            auto [cnt,ch]=pq.top();
            pq.pop();
            if (ans.size()>=2 && ans.back()==ch && ans[ans.size()-2]==ch){
                if (pq.empty()){
                    break;
                }
                auto [cnt2,ch2]=pq.top();
                pq.pop();
                ans+=ch2;
                cnt2--;
                if ((cnt2>0)){
                    pq.push({cnt2,ch2});
                }
                pq.push({cnt,ch});
            }
            else{
                ans+=ch;
                cnt--;
                if (cnt>0){
                    pq.push({cnt,ch});
                }
            }
        }
        return ans;
    }
};