#!/usr/bin/pypy
# -*- coding: utf-8 -*-


def main():
    h1, m1 = map(int, input().split(':'))
    h2, m2 = map(int, input().split(':'))
    if m2 < m1:
        m2 += 60
        h2 -= 1
    if h2 < h1:
        h2 += 24

    m3 = m1 + (m2 - m1) / 2 + (h2 - h1) * 30
    h3 = h1 + m3 // 60
    m3 %= 60

    if h3 >= 24:
        h3 -= 24

    print('{:02d}:{:02d}'.format(int(h3), int(m3)))


if __name__ == '__main__':
    main()
