class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        int one=0;
        int n=s.size();
        string result="";
        for (int right=0;right<n;right++){
            if (s[right]=='1'){
                one++;
            }
            if (one==k){
                while(s[left]=='0'){
                    left++;}
                    string temp=s.substr(left,right-left+1);
                    if (result.empty() || (temp.size()<result.size()) ||(temp.size()==result.size() && temp<result)){
                        result=temp;
                    }
                one--;
                left++;
            }
        }
        return result;
    }
};