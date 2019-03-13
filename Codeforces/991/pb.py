# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    n = int(input())
    nums = rli()
    nums.sort()
    ans = sum(nums)
    if ans / float(n) >= 4.5:
        print(0)
        return
    for i in range(len(nums)):
        ans += 5 - nums[i]
        if ans / float(n) >= 4.5:
            print(i + 1)
            return


if __name__ == '__main__':
    main()
