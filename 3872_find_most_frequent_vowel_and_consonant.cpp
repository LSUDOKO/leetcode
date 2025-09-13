class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char,int>vowels;
        unordered_map<char,int>cons;
        int maxi_vol=0;
        int maxi_cons=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o' || s[i]=='u'){
                vowels[s[i]]++;
            }
            else{
                cons[s[i]]++;
            }
        }
        for (auto p:vowels){
            maxi_vol=max(maxi_vol,p.second);
        }
        for (auto p:cons){
            maxi_cons=max(maxi_cons,p.second);
        }
        return maxi_vol+maxi_cons;
    }
};