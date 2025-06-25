class Solution {
public:
    bool rotateString(string s, string goal) {
        string copy=s;
        while(true){
            if (s.length() > 1) {
            s = s.substr(1) + s[0];
            if(s==goal){
                return true;
                break;
            }
            else if(s==copy) {
                return false;
                break;
            }
            }
            else{
                return false;
            }
        }
    }
};