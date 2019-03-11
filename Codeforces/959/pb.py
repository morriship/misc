#!/usr/bin/python2.7
# -*- coding: utf-8 -*-

# from functools import reduce


def build(x, y):
    x[y[0]] = x[y[1]]


def main():
    n, k, m = map(int, raw_input().split())
    name = raw_input().split()
    ni = {name[idx]: idx for idx in range(len(name))}
    cost = map(int, raw_input().split())
    cm = [1e19 for _ in range(k)]
    groups = {}
    for x in range(k):
        for w in raw_input().split()[1:]:
            w = int(w) - 1
            groups[w] = x
            cm[x] = min(cm[x], cost[w])
    ans = 0
    for x in raw_input().split():
        ans += cm[groups[ni[x]]]
    print(ans)


if __name__ == '__main__':
    main()
