class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(i<=100){
            int pr=1;
            string s=to_string(i);
            for (int j=0;j<s.size();j++){
                pr*=(s[j]-'0');
            }
            if (pr%t==0){
                return i;
            }
            i++;
        }
        return -1;
    }
};