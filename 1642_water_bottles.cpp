class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long long  sum=numBottles;
        long long rem=0;
        while(numBottles>0){
            int a=(numBottles/numExchange);
            rem+=(numBottles%numExchange);
            if (rem>=numExchange){
                sum+=rem/numExchange;
                numBottles++;
                rem=rem%numExchange;
            }
            // if (a==0){
            //     sum++;
            // }
            sum+=a;
            numBottles=numBottles/numExchange;
        }
        return sum;
        // long long sum = numBottles;
        // long long rem = 0;
        // while (numBottles > 0) {
        //     int a = numBottles / numExchange;
        //     rem += (numBottles % numExchange);

        //     int extra = rem / numExchange;
        //     rem = rem % numExchange;

        //     sum += a + extra;                         
        //     numBottles = a + extra;                   
        // }
        // return (int)sum;
    }
};