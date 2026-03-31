from queue import LifoQueue

n = input().strip()
t = int(input())
ks = [int(input()) for _ in range(t)]

for k in ks:
    S = LifoQueue()
    remove = k
    for digit in n:
        while not S.empty() and remove > 0 and S.queue[-1] < digit:
            S.get()
            remove -= 1
        S.put(digit)

    result = ''.join(list(S.queue)[:len(n) - k])
    print(result)
