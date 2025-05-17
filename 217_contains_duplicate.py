class Solution(object):
    def containsDuplicate(self, nums):
        h=set()
        for num in nums:
            if num in h:
                return True
            else:
                h.add(num)
        return False