class Solution {
public:
    bool isPalin(string s){
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getAllParts(string s,vector<string> &partitions,       vector<vector<string>> &ans){
        if( s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for (int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if (isPalin(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+1),partitions,ans);
                partitions.pop_back();
            }


        }
    
    }
    
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitions;
        getAllParts(s,partitions,ans);
        return ans;
    }
};