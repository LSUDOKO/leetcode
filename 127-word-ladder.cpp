class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(!st.count(endWord)){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int step=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string front=q.front();
                q.pop();
                if(front==endWord){
                    return step;
                }
                for (int i=0;i<front.size();i++){
                    char original=front[i];
                    for (char j='a';j<='z';j++){
                        if (j==original){
                            continue;
                        }
                        front[i]=j;
                        if(st.count(front)){
                            q.push(front);
                            st.erase(front);
                        }
                    }
                    front[i]=original;
                }

            }
            step++;
        }
        return 0;
    }
};