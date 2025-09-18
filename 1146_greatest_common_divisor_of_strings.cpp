class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if ((str1+str2)==(str2+str1)){
            int result=gcd(str1.size(),str2.size());
            string final=str1.substr(0,result);
            return final;
        }
        else{
            return "";
        }
    }
};