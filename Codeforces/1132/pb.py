# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    int(input())
    nums = rli()
    int(input())
    qs = rli()
    ans = sum(nums)
    nums.sort()
    for q in qs:
        print(ans - nums[-q])


if __name__ == '__main__':
    main()
