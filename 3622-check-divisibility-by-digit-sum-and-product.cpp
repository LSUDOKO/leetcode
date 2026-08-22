class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int size=s.size();
        long long sum=0;
        long long prod=1;
        for (int i=0;i<s.size();i++){
            sum+=(s[i]-'0');
            prod*=(s[i]-'0');
        }
        if (n%(sum+prod)==0){
            return true;
        }
        else{
            return false;
        }
    }
};