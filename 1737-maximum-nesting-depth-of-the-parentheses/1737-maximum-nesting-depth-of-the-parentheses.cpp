class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int ans=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                ans++;
                maxi=max(maxi,ans);
            }
            else if (s[i]==')'){
                ans--;
            }
        }
        return maxi;
    }
};