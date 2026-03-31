if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    p = 0
    D = {}
    for i, x in enumerate(a):
        if x in D and D[x] >= p:
            p = D[x] + 1
        res = max(res, i - p + 1)
        D[x] = i
    print(res)
