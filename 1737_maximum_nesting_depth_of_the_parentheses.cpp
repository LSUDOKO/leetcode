class Solution {
public:
    int maxDepth(string s) {
        // int maxi=0;
        // int count=0;
        // for (int i=0;i<s.size();i++){
        //     if (s[i]=='('){
        //         count++;
        //         maxi=max(count,maxi);
        //     }
        //     else if (s[i]==')'){
        //         count--;
        //     }
        // }
        // return maxi;
        stack<char> st;
        int maxi = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
                maxi = max(maxi, (int)st.size());
            } 
            else if (c == ')') {
                if (!st.empty()) {
                    st.pop();
                } 
                else {
                    return -1;
                }
            }
        }

        if (!st.empty()) return -1;

        return maxi;
    }
};