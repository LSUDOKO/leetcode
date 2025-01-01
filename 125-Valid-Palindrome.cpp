#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s,int i=0) {
        int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      while (l < r && !isalnum(s[l]))
        ++l;
      while (l < r && !isalnum(s[r]))
        --r;
      if (tolower(s[l]) != tolower(s[r]))
        return false;
      ++l;
      --r;
    }

    return true;
    }
};