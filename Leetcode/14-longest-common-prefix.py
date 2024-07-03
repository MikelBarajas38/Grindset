class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        if not strs:
            return ""
        
        prefix_dict = {}
        x=len(strs[0])

        for i in range(len(strs[0])+1):
            prefix_dict[i] = strs[0][:i]

        for i in strs:

            while not i.startswith(prefix_dict[x]):
                x-= 1

            val = prefix_dict[x]
        
        return val
        