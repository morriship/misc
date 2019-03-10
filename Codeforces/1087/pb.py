# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    n, k = rli()
    ans = float('inf')
    for i in range(1, k):
        if n % i == 0:
            x = n / i
            ans = min(ans, int(x * k + i))
    print(ans)


if __name__ == '__main__':
    main()
