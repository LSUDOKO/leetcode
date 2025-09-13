class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int> st;
        unordered_set<int>name;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                st.push(i);
            }
            else if (s[i]==')'){
                if (!st.empty()){
                    st.pop();
                }
                else{
                    name.insert(i);
                }
            }
        }
        // for (( this kind of case 
        while(!st.empty()){
            name.insert(st.top());
            st.pop();
        }
        string result="";
        for (int i=0;i<n;i++){
            if (name.find(i)==name.end()){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};