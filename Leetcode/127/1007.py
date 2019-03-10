from collections import defaultdict

INF = float('inf')

def solve(A, B, num):
    a = 0
    b = 0
    cant = 0
    for i in range(len(A)):
        if A[i] == num:
            if B[i] != num:
                b += 1
        elif B[i] == num:
            a += 1
        else:
            cant = 1
            break
    if cant:
        return INF
    return min(a, b)

class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        a = solve(A, B, A[0])
        b = solve(A, B, B[0])
        if min(a, b) == INF:
            return -1
        return min(a, b)
