from queue import LifoQueue
def func(a, idx):
    S = LifoQueue()
    S.put((2e9, -1))
    L = [0]*len(a)
    for i, x in zip(idx, a):
        while x >= S.queue[-1][0]:
            S.get()
        L[i] = S.queue[-1][1]
        S.put((x, i))
    return L
if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    L = func(a, range(n))
    R = func(a[::-1], range(n-1, -1, -1))
    for i in range(n):
        if L[i] > -1 and R[i] > -1:
            print(L[i] if i - L[i] <= R[i] - i else R[i], end=" ")
        else:
            print(L[i] + R[i] + 1, end=" ")