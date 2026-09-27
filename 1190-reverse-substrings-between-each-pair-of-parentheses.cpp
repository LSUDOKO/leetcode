class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> skip;
        string result;
        for (char c: s){
            if (c=='('){
                skip.push(result.size());
            }
            else if (c==')'){
                int l=skip.top();
                skip.pop();
                reverse(result.begin()+l,result.end());
            }
            else{
                result+=c;
            }
        }
        return result;
    }
};