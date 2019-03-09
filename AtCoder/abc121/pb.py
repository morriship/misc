def main():
    n, m, c = map(int, input().split())
    b = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        a = list(map(int, input().split()))
        tmp = 0
        for j in range(m):
            tmp += a[j] * b[j]
        tmp += c
        if tmp > 0:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
