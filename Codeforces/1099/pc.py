# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    s = input()
    k = int(input())
    cnt = 0
    candy_cnt = 0
    snow_cnt = 0
    for i in range(len(s)):
        if s[i] == '?':
            candy_cnt += 1
        elif s[i] == '*':
            snow_cnt += 1
        else:
            cnt += 1
    if k < cnt - snow_cnt - candy_cnt:
        print('Impossible')
    elif k > cnt and snow_cnt == 0:
        print('Impossible')
    else:
        need = k - cnt
        ans = ''
        for i in range(len(s)):
            if s[i] == '?':
                if need < 0:
                    need += 1
                    ans = ans[:-1]
            elif s[i] == '*':
                if need > 0:
                    ans = ans + s[i - 1] * need
                    need = 0
                elif need < 0:
                    need += 1
                    ans = ans[:-1]
            else:
                ans = ans + s[i]
        print(ans)


if __name__ == '__main__':
    main()
