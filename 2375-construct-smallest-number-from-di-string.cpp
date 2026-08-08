class Solution {
public:
    bool solve(string &pattern,string &temp,vector<bool>&used){
        if (temp.size()==pattern.size()+1){
            return true;
        }
        for (int i=1;i<=9;i++){
            if (used[i]){
                continue;
            }
            if (!temp.empty()){
                int prev=temp.back()-'0';
                int index=temp.size()-1;
                if (pattern[index]=='I' && prev>=i){
                    continue;
                }
                if (pattern[index]=='D' && prev<=i)
                continue;

            }

            temp.push_back(char('0'+i));
            used[i]=true;
            if (solve(pattern,temp,used)){
                return true;
            }
            temp.pop_back();
            used[i]=false;
        }
        return false;
    }
    string smallestNumber(string pattern) {
        string temp;
        vector<bool>used(10,false);
        solve(pattern,temp,used);
        return temp;
    }
};