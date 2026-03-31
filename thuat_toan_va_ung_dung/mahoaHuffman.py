from queue import PriorityQueue
s = input().strip()
freq = {}
for c in s:
    freq[c] = freq.get(c, 0) + 1
pq = PriorityQueue()
for f in freq.values():
    pq.put(f)
res = 0
while pq.qsize() > 1:
    x = pq.get()
    y = pq.get()
    total = x + y
    res += total
    pq.put(total)
print(res)