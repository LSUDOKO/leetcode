class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        int result=0;
        vector<int>freq(26,0);
        while(j<n){
            int idx=s[j]-'a';
            freq[idx]++;
            while(freq[idx]>2){
                freq[s[i]-'a']--;
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};