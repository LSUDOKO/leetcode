class Solution {
public:
    vector<int> getLPS(vector<int>& text) {
        int n = text.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n) {
            if (text[i] == text[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool KMPSearch(vector<int>& vec1, vector<int>& text) {
        vector<int> lps = getLPS(vec1);

        int i = 0, j = 0;

        while (i < text.size()) {
            if (vec1[j] == text[i]) {
                i++;
                j++;
            }

            if (j == vec1.size()) {
                return true;
            }
            else if (i < text.size() && vec1[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return false;
    }
    bool isrotationpossible(vector<int>&vec1,vector<int>&vec2){
        vector<int>txt=vec2;
        txt.insert(end(txt),begin(vec2),end(vec2));
        return KMPSearch(vec1,txt);
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());

        int result=0;
        for (int k=1;k<=n;k++){
            if(n%k!=0){
                continue;
            }
            bool valid=true;
            for (int start=0;start<n;start+=k){
                vector<int>vec1(begin(nums)+start,begin(nums)+start+k);
                vector<int>vec2(begin(sorted)+start,begin(sorted)+start+k);
                if(!isrotationpossible(vec1,vec2)){
                valid=false;
                break;
}
            }
            if(valid){
                result+=k;
            }
        }
        return result;
    }
};