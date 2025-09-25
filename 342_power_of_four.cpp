class Solution {
public:
    //AProch 1
    bool isPowerOfFour(int n) {
    //     if (n <= 0) return false;
    // if ((n & (n - 1)) != 0) return false;
    // return (n & 0x55555555) != 0;
    // }

    //AProch 2
    // while(n>1){
    //     if (n%4!=0){
    //         return false;
    //     }
    //     n=n/4;
    // }
    // return n==1;}//timexomplexity log4(n)

    //Approach 3
    // if (n<=0){
    //     return false;
    // }
    // int x=log(n)/log(4);
    // if (pow(4,x)==n){
    //     return true;
    // }
    // else {
    //     return false;
    // }
    // 
    //log(n)+log(x)
    //approch 4
    if (n <= 0) return false;
    if (((n & (n - 1)) == 0) && ((n - 1) % 3 == 0)) {
        return true;
    }
    return false;}
};