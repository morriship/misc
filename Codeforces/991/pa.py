# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    a, b, c, n = rli()
    if c > a or c > b:
        print(-1)
        return
    if a + b - c > n - 1:
        print(-1)
        return
    print(n - a - b + c)


if __name__ == '__main__':
    main()
