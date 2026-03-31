#chao don K59
from queue import LifoQueue

def fun(a,id):
    S=LifoQueue()
    S.put((2e9,-1))
    L=[-1]*len(a)
    for i,x in zip(id,a):
        while x>= S.queue[-1][0]: S.get()
        L[i]=(S.queue[-1][1])
        S.put((x,i))
    return L

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    L = fun(a, range(n))
    R = fun(a[::-1], range(n-1, -1, -1))

    for i in range(n):
        if L[i] > 0 and R[i] > 1: print(L[i] if i - L[i] <= R[i] - i else R[i], end=" ")
        else: print(L[i] + R[i] + 1, end=" ")


