def icpc(s):
    p = set()
    kq = 0
    for c in s:
        if c not in p:
            p.add(c)
            kq += 2
        else:
            kq += 1
    return kq


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input().strip()
        print(icpc(s))
