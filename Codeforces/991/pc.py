# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def eat(n, k):
    ans = 0
    while n:
        ans += min(n, k)
        n -= min(n, k)
        n -= n // 10
    return ans


def main():
    n = int(input())
    k = n
    now = 1 << 60
    need = n // 2 + (n % 2 != 0)
    while now:
        if k - now > 0 and eat(n, k - now) >= need:
            k -= now
        now >>= 1
    print(k)


if __name__ == '__main__':
    main()
