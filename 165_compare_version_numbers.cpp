class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (i < n1 || j < n2) {
            int v1 = 0, v2 = 0;


            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i++] - '0');
            }
            ++i;  


            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j++] - '0');
            }
            ++j;  

            if (v1 < v2) 
            return -1;
            if (v1 > v2) 
            return 1;
        }
        return 0;
    }
};