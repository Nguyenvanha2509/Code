from collections import deque

n, k = map(int, input().split())
Q = deque()

for i, x in enumerate(map(int, input().split()), 1):
    while len(Q) and Q[-1][0] <= x: Q.pop()
    Q.append((x, i))
    while i - Q[0][1] >= k: Q.popleft()
    if i >= k: print(Q[0][0], end=" ")
