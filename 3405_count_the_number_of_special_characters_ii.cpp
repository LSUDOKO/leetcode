class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        vector<int>small(26,-1);
        vector<int>big(26,-1);
        for (int i=0;i<word.size();i++){
            char c=word[i];
            if (islower(c)){
                small[c-'a']=i;
            }
            else{
                if (big[c-'A']==-1)
                    big[c-'A']=i;
            }
        }
        for (int i=0;i<26;i++){
            if (small[i]!=-1 && big[i] && small[i]<big[i]){
                count++;
            }
        }
        return count;
    }
};