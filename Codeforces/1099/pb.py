# -*- coding: utf-8 -*-

import math


def rli():
    return list(map(int, input().split()))


def main():
    n = int(input())
    nn = int(math.sqrt(n))
    if nn * nn >= n:
        print(nn + nn)
    elif nn * (nn + 1) >= n:
        print(nn + nn + 1)
    else:
        print(nn + nn + 2)


if __name__ == '__main__':
    main()
