def banh():
    import sys
    input = sys.stdin.readline

    n = int(input().strip())
    a = list(map(int, input().split()))

    tong = sum(a)
    trai = 0
    kq = float('inf')

    for i in range(n - 1):
        trai += a[i]
        hieu = abs(tong - 2 * trai)
        if hieu < kq:
            kq = hieu

    print(kq)


if __name__ == "__main__":
    banh()
