class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;
        for (char &c:s){
            if (st.empty()){
                if(c=='(')
                st.push(c);
                // else 
                // return -1;
            }
            else if (!st.empty()){
                if (c=='('){
                st.push(c);
                ans+=c;}
                else if (c==')'){
                    st.pop();
                    if (!st.empty()){
                        ans+=c;
                    }
                }
            }
        }
        return ans;
    }
};