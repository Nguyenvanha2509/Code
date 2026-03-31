n = int(input())
s = list(map(int, input().split()))
s.sort()
res = (s[-1] - s[1]) * (s[-2] - s[0])
print(res)5