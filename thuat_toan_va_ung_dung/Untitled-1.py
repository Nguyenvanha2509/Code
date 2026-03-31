def solve():
    import sys
    input = sys.stdin.readline

    n = int(input().strip())
    arr = list(map(int, input().split()))

    arr.sort()

    # Trường hợp chọn 2 số
    case1 = arr[-1] * arr[-2]        # 2 số lớn nhất
    case2 = arr[0] * arr[1]          # 2 số âm nhỏ nhất

    # Trường hợp chọn 3 số
    case3 = arr[-1] * arr[-2] * arr[-3]   # 3 số lớn nhất
    case4 = arr[0] * arr[1] * arr[-1]     # 2 số âm nhỏ nhất và số dương lớn nhất

    print(max(case1, case2, case3, case4))
