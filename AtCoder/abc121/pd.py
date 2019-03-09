def solve(a):
    if a <= 1:
        return a
    if a % 2 == 0:
        return a ^ ((a // 2) % 2)
    return ((a + 1) // 2) % 2


def main():
    a, b = map(int, input().split())
    if a > 0:
        a -= 1
    print(solve(a) ^ solve(b))


if __name__ == '__main__':
    main()
