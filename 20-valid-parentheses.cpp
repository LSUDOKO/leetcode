class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &c:s){
            if (st.empty() || c=='{' || c=='(' || c=='['){
                st.push(c);
            }
            if (c=='}'){
                if (st.top() =='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if (c==']'){
                if (st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(c==')'){
                if (st.top()=='(')
                    st.pop();
                else{
                    return false;
                }
            }
        }
        if (st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};