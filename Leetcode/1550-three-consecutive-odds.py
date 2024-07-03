class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:

        odd_counter = 0

        for x in arr:
            if x % 2 == 0:
                odd_counter = 0
            else:
                odd_counter += 1
                if odd_counter == 3:
                    return True
        
        return False

        