def solve():
    import sys
    input = sys.stdin.readline

    n = int(input().strip())
    a = list(map(int, input().split()))
    a.sort()

    case1 = a[-1] * a[-2]
    case2 = a[0] * a[1]
    case3 = a[-1] * a[-2] * a[-3]
    case4 = a[0] * a[1] * a[-1]

    print(max(case1, case2, case3, case4))

if __name__ == "__main__":
    solve()
