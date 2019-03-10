# -*- coding: utf-8 -*-

import sys
import random


def rli():
    return list(map(int, input().split()))


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def main():
    n = int(input())
    st = int(0)
    ed = int(1e9)
    cnt = 0
    while st < ed:
        mi = (st + ed) // 2
        cnt += 1
        print('> {}'.format(mi))
        sys.stdout.flush()
        res = int(input())
        if res == 0:
            ed = mi
        else:
            st = mi + 1

    lst = st
    used = set()
    nums = [lst]
    while cnt < 60 and len(used) < n:
        x = random.randint(1, n)
        while x in used:
            x = random.randint(1, n)
        used.add(x)
        cnt += 1
        print('? {}'.format(x))
        sys.stdout.flush()
        res = int(input())
        if res != lst:
            nums.append(res)
    nums.sort()
    diff = nums[1] - nums[0]
    for i in range(2, len(nums)):
        diff = gcd(diff, nums[i] - nums[i - 1])
    print('! {} {}'.format(lst - diff * (n - 1), diff))


if __name__ == '__main__':
    main()
