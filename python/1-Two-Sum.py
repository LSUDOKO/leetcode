class Solution(object):
\tdef twoSum(self, nums, target):
\t\tmapping = {}

\t\tfor index, val in enumerate(nums):
\t\t\tdiff = target - val
\t\t\tif diff in mapping:
\t\t\t\treturn [index, mapping[diff]]
\t\t\telse:
\t\t\t\tmapping[val] = index
        