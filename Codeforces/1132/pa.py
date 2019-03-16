# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    a = int(input())
    b = int(input())
    c = int(input())
    d = int(input())
    if a != d or (c != 0 and a == d and a == 0):
        print(0)
    else:
        print(1)


if __name__ == '__main__':
    main()
