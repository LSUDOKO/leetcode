class Solution(object):
    def reverseWords(self, s):
        a=s.split(" ")
        b=""
        for i in a[::-1]:
            if (i != ""):
                b += i + " "
        return b.strip()