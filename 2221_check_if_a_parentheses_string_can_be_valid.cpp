// class Solution {
// public:
//     // bool check(string s){
//     //     stack<char> st;
//     //     for (int i=0;i<s.size();i++){
//     //         if (s[i]=='('){
//     //             st.push('(');
//     //         }
//     //         else{
//     //             if (!st.empty())
//     //                 st.pop();
//     //         }
//     //     }
//     //     if (st.empty()){
//     //         return true;
//     //     }
//     //     else {
//     //         return false ;
//     //     }
//     // }
//     // bool canBeValid(string s, string locked) {
//     //     stack<char> st;
//     //     for (int i=0;i<s.size();i++){
//     //         if (s[i]=='('){
//     //             if (st.empty()){
//     //                 st.push('(');
//     //             }
//     //             else{
//     //                 if (check(s)){
//     //                     return true;
//     //                 }
//     //                 // else {
//     //                 //     return false;
//     //                 // }
//     //             }
                

//     //         }
//     //         else {
//     //             if (st.empty()){
//     //                 if (locked[i]=='0'){
//     //                     st.push('(');
//     //                 }
//     //                 else{
//     //                     return false;
//     //                 }
//     //             }
//     //             else{
//     //                 st.pop();
//     //             }
//     //         }
//     //     }
//     //     if (st.empty()){
//     //         return true;
//     //     }
//     //     else {
//     //         return false;
//     //     }
//     // }
//     bool canBeValid(string s, string locked) {



//     }
// };

class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int n = s.size();
        if (n & 1) return false;               

        stack<int> open, free;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                free.push(i);
            } else if (s[i] == '(') {          
                open.push(i);
            } else {                             
                if (!open.empty()) open.pop();   
                else if (!free.empty()) free.pop(); 
                else return false;
            }
        }


        while (!open.empty() && !free.empty() && open.top() < free.top()) {
            open.pop();
            free.pop();
        }
        return open.empty();
    }
};