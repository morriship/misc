class Solution:
    def clumsy(self, N: int) -> int:
        lst = []
        while N > 0:
            x = N
            N -= 1
            if N > 0:
                x *= N
                N -= 1
            if N > 0:
                x //= N
                N -= 1
            lst.append(x)
            if N > 0:
                lst.append(N)
                N -= 1
        ans = lst[0]
        for i in range(1, len(lst), 2):
            ans += lst[i]
            if i + 1 < len(lst):
                ans -= lst[i + 1]
        return ans
