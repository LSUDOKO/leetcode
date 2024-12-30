class Solution {
public:
    int countPrimes(int n) {
    if(n==0) return 0;
        vector<bool>prime(n,true);
        int ans=0;
        prime[0]=prime[1]=false;
        for(int i=0;i<n;i++){
            if(prime[i]){
                ans++;
                int j=2*i;
                while(j<n){
                    prime[j]=false;
                    j+=i;
                }
            }
        }
        return ans;
    }
};