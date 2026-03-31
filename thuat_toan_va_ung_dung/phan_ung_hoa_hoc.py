import queue
A = [[] for i in range(10**5+2)]
d = [0]*(10**5+1)

def Tim(k, Q):
    global d, A
    Q.put(k)
    dem = 1
    d[k] = 1
    while Q.qsize():
        u = Q.get()
        for v in A[u]:
            if d[v] == 0:
                dem += 1
                d[v] = 1
                Q.put(v)
    return dem

if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(m):
        x, y = map(int, input().split())
        A[x].append(y)
        A[y].append(x)
    res = 1
    Q = queue.Queue()
    for i in range(1, n + 1):
        if d[i] == 0:
            res = res * 2**(Tim(i, Q)-1)
    print(res)
