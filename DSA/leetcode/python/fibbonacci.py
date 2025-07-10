# The Fibonacci numbers, commonly denoted F(n) form a
# sequence, called the Fibonacci sequence, such that each number is the sum of the two
# preceding ones, starting from 0 and 1. That is, F(0) = 0 , F(1) = 1 , and F(n) = F(n
# - 1) + F(n - 2) for n > 1 . Given n , calculate F(n) .

from functools import lru_cache

class Solution :
    @lru_cache(maxsize=None) # Cache results of fibbonacci calls 
    def fib(self , n:int) ->int :
        if n <= 1 : 
            return n 
        return self.fib(n-1)+self.fib(n-2)

#Test cases 
sol = Solution()
print(sol.fib(2)) # Expected: 1
print(sol.fib(3)) # Expected: 2
print(sol.fib(4)) # Expected: 3
print(sol.fib(10)) # Expected: 55
print(sol.fib(30)) # Computes very quickly due to caching
