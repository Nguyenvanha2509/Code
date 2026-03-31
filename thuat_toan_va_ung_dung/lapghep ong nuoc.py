from queue import PriorityQueue
pq = PriorityQueue()
n, k = map(int, input().split())
for x in map(int, input().split()):
    pq.put(x)
res = 0
while pq.qsize() > 1:
    t = 0
    cnt = min(k, pq.qsize())
    for _ in range(cnt):
        t += pq.get()
    pq.put(t)
    res += t

print(res)