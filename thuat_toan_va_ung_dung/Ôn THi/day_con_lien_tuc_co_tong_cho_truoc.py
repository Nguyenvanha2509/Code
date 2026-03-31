D = {0: 0}
n, T = map(int, input().split())
a = list(map(int, input().split()))
s = 0
res = 0
for i, x in enumerate(a, 1):
    s += x
    L = D.get(s - T, i)
    res = max(res, i - L)
    if s not in D:
        D[s] = i
print(res)