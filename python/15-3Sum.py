class Solution():
    def threeSum(self, nums):
        \\\
        :type nums: List[int]
        :rtype: List[List[int]]
        \\\
        res=[]
        nums.sort()
        lenght=len(nums)
        for i in range(lenght-2):
            if i>0 and nums[i]==nums[i-1]:
                continue 
            l=i+1
            r=lenght-1
            while l<r:
                total=nums[i]+nums[l]+nums[r]
                if total<0:
                    l=l+1
                elif total>0:
                    r=r-1
                else:
                    res.append([nums[i],nums[l],nums[r]])
                    while l<r and nums[l]==nums[l+1]:
                        l=l+1
                    while l<r and nums[r]==nums[r-1]:
                        r=r-1
                    l=l+1
                    r=r-1
        return res