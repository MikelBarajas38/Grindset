class Solution:
    def romanToInt(self, s: str) -> int:
        x = 0
        val_dict = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        special_vals = {"IV", "IX", "XL", "XC", "CD", "CM"}

        for i in range(len(s)-1):
            if str(s[i] + s[i+1]) in special_vals:
                x -= val_dict[s[i]]*2

        for c in s:
            x += val_dict[c]
        
        return x