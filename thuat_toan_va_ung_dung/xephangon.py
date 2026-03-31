from queue import LifoQueue

S = LifoQueue()
n = int(input())
a = list(map(int, input().split()))
res = 0

for x in a:
    count = 1
    while not S.empty():
        top = S.queue[-1]
        if top[0] < x:
            res += top[1]
            S.get()
        elif top[0] == x:
            res += top[1]
            count += top[1]
            S.get()
        else:
            res += 1
            break
    S.put([x, count])

print(res)
