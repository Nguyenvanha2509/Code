from queue import PriorityQueue
n = int(input())
V = list(map(int, input().split()))
T = list(map(int, input().split()))
pq = PriorityQueue()
offset = 0
for v, t in zip(V, T):
    pq.put(v + offset)
    melted = 0
    while pq.qsize() and pq.queue[0] - offset <= t:
        melted += pq.get() - offset
    melted += t * pq.qsize()
    print(melted, end=" ")
    offset += t