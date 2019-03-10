# -*- coding: utf-8 -*-


def rli():
    return list(map(int, input().split()))


def put(ans, sx, sy1, sy2, ex, ey):
    if sy1 > sy2:
        sy1, sy2 = sy2, sy1
    y = -1
    if sy1 <= ey <= sy2:
        y = ey
    elif ey < sy1:
        y = sy1
    elif ey > sy2:
        y = sy2

    for i in range(sx + 1, ex, 1):
        ans.append((i, y))
    if ex != sx and ey != y:
        ans.append((ex, y))

    if y > ey:
        for i in range(y - 1, ey, -1):
            ans.append((ex, i))
    else:
        for i in range(y + 1, ey, 1):
            ans.append((ex, i))


def main():
    nums = []
    ans = []
    for i in range(3):
        a, b = rli()
        nums.append((a, b))
    nums.sort()
    ans.append(nums[0])
    put(ans, nums[0][0], nums[0][1], nums[0][1], nums[1][0], nums[1][1])
    ans.append(nums[1])
    put(ans, nums[1][0], nums[0][1], nums[1][1], nums[2][0], nums[2][1])
    if nums[2] not in ans:
        ans.append(nums[2])
    print(len(ans))
    for i in range(len(ans)):
        print('{} {}'.format(ans[i][0], ans[i][1]))


if __name__ == '__main__':
    main()
