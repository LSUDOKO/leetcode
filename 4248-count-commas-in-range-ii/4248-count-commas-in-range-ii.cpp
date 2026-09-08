class Solution {
    #define ll long long
public:
    long long countCommas(long long n) {
        ll ans=0;
        for(ll x=1000;x<=n;x*=1000){
            ans+=n-x+1;
            if(x>n){
                break;
            }
        }
        return ans;
    }
};