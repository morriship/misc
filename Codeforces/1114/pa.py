# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    x, y, z = rli()
    a, b, c = rli()
    if x > a or x + y > a + b or x + y + z > a + b + c:
        print('NO')
    else:
        print('YES')


if __name__ == '__main__':
    main()
