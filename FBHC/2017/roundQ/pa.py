import math


def read_input():
    case_number = int(raw_input())
    for i in xrange(case_number):
        yield raw_input()

def check_in_circle(x, y):
    return (50 - x) ** 2 + (50 - y) ** 2 <= 2500


def cal_xy(p):
    p = math.pi * p / 50.0
    x = math.sin(p)
    y = math.cos(p)
    return (x, y)


def cross(ax, ay, bx, by):
    return ax * by - ay * bx

def check_is_black(p, x, y):
    x -= 50
    y -= 50
    fx, fy = 0, 50
    sx, sy = cal_xy(p)
    if cross(fx, fy, sx, sy) <= 0:
        return cross(fx, fy, x, y) <= 0 and cross(sx, sy, x, y) >= 0
    else:
        return cross(fx, fy, x, y) <= 0 or cross(sx, sy, x, y) >= 0

def main():
    for index, line in enumerate(read_input(), 1):
        p, x, y = map(lambda x: int(x), line.split())
        if p != 0 and check_in_circle(x, y) and check_is_black(p, x, y):
            ans = 'black'
        else:
            ans = 'white'
        print 'Case #{}: {}'.format(index, ans)


if __name__ == '__main__':
    main()