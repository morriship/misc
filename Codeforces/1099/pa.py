# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    w, h = rli()
    stones = []
    for i in range(2):
        u, d = rli()
        stones.append((d, u))
    stones.sort()
    stones.reverse()
    stones.append((float('inf'), 0))
    now = 0
    si = 0
    while h:
        w += h
        if h == stones[si][0]:
            w -= stones[si][1]
            si += 1
        if w < 0:
            w = 0
        now += 1
        h -= 1
    print(w)


if __name__ == '__main__':
    main()
