#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        result += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0) return result;

        result += ".";
        unordered_map<long long, int> remainderPos;

        while (remainder != 0) {
            if (remainderPos.find(remainder) != remainderPos.end()) {
                result.insert(remainderPos[remainder], "(");
                result += ")";
                break;
            }

            remainderPos[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result;
    }
};