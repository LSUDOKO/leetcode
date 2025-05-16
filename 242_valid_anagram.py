class Solution(object):
    def isAnagram(self, s, t):
        count_s=Counter(s);
        count_t=Counter(t);
        if count_s==count_t:
            return True;
        else :
            return False;