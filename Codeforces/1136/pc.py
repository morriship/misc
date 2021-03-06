# -*- coding: utf-8 -*-

from collections import defaultdict


def rli():
    return list(map(int, input().split()))


def main():
    n, m = rli()
    cnt = [defaultdict(int) for i in range(n + m + 10)]
    for i in range(n):
        nums = rli()
        for j in range(m):
            cnt[i + j][nums[j]] += 1
    for i in range(n):
        nums = rli()
        for j in range(m):
            cnt[i + j][nums[j]] -= 1
    for i in range(n + m + 10):
        for v in cnt[i].values():
            if v != 0:
                print('NO')
                return
    print('YES')


if __name__ == '__main__':
    main()
