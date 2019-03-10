# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    n, m, k = rli()
    nums = rli()
    x = []
    for i in range(len(nums)):
        x.append((nums[i], i))
    choosed = [0] * len(nums)
    tot = 0
    x.sort()
    x = x[-1::-1]
    for i in range(m * k):
        tot += x[i][0]
        choosed[x[i][1]] = 1
    ans = []
    cnt = 0
    for i in range(len(nums)):
        if choosed[i]:
            cnt += 1
            cnt %= m
            if cnt == 0:
                ans.append(i + 1)
    print(tot)
    print(' '.join(map(str, ans[:-1])))


if __name__ == '__main__':
    main()
