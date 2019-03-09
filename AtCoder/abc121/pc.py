def main():
    n, m = map(int, input().split())
    nums = []
    for i in range(n):
        a, b = map(int, input().split())
        nums.append((a, b))
    nums.sort()
    total = 0
    for i in range(n):
        if m <= 0:
            break
        a, b = nums[i]
        total += a * min(b, m)
        m -= min(b, m)
    print(total)


if __name__ == '__main__':
    main()
