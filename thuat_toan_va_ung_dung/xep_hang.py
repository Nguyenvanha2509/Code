from queue import LifoQueue

S=LifoQueue()
n = int(input())
a = list(map(int, input().split()))
stack = []
res = 0

for x in a:
    while S.qsize() and S.queue[-1][0] < x:
        res += S.queue[-1][1]
        S.get()
    if S.qsize() and S.queue[-1][0]==x:
        res += S.queue[-1][1]+(S.qsize()>1)
        S.queue[-1][1] += 1
    else:
        res += (S.qsize()>0)
        S.put([x,1])

print(res)
