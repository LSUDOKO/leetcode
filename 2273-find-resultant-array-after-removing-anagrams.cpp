class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for (int i=1;i<words.size();i++){
            vector<int>first(26,0);
            vector<int>second(26,0);
            if (words[i].size()!=words[i-1].size()){
                ans.push_back(words[i]);
                continue;
            }
            for (int j=0;j<words[i].size();j++){
                first[words[i][j]-'a']++;
                second[words[i-1][j]-'a']++;
            }
            bool same=true;
            for (int j=0;j<26;j++){
                if (first[j]!=second[j]){
                    same=false;
                    break;
                }
            }
            if (!same){
                ans.push_back(words[i]);
                continue;
            }
        }
        return ans;
    }
};