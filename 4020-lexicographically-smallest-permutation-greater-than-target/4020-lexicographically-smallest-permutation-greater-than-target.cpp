class Solution {
    string result="";
    bool solve(string &curr,vector<int>&count,string &target,int i, bool greater){
        if (i==target.size()){
            if(greater){
                result=curr;
                return true;
            }
            else{
                return false;
            }
        }
        for (char ch='a';ch<='z';ch++){
            if (count[ch-'a']==0){
                continue;
            }
            if (greater==false && ch<target[i]){
                continue;
            }
            curr.push_back(ch);
            count[ch-'a']--;

            bool isgreater=greater|| ch>target[i];
            if (solve(curr,count,target,i+1,isgreater)){
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
public:

    string lexGreaterPermutation(string s, string target) {
        vector<int>count(26,0);
        for (char c : s){
            count[c-'a']++;
        }
        string curr="";
        solve(curr,count,target,0,false);
        return result;
    }
};