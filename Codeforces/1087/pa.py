# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def main():
    s = input()
    ans = []
    if len(s) > 1 and len(s) % 2 == 1:
        ans.append(s[0])
        s = s[1:]
    st, ed = 0, len(s) - 1
    while st < ed:
        ans.append(s[ed])
        ans.append(s[st])
        st += 1
        ed -= 1
    if st == ed:
        ans.append(s[st])
    ans.reverse()
    print(''.join(ans))


if __name__ == '__main__':
    main()
