class Solution {
public:
    bool checkPerfectNumber(int num) {
        long sum=0;
        for (int i=1;i<num;i++){
            if (num%i==0){
                sum+=i;
            }
        }
    if (num==sum){
        return true;
    }
    else{
        return false;
    }
    
    }
};