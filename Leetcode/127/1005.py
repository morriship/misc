class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        A.sort()
        for i in range(len(A)):
            if K <= 0:
                break
            if A[i] < 0:
                A[i] = -A[i]
                K -= 1
        A.sort()
        K %= 2
        if K:
            A[0] = -A[0]
        return sum(A)
