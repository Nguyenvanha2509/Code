from queue import LifoQueue
def hoachat(x):
    K = {'(':0, 'C':12, 'H':1, 'O':16}
    L = LifoQueue()
    for c in x:
        if c in K.keys(): L.put(K[c])
        
        elif c==')':
            s=0
            while L.queue[-1] != 0:
                s += L.get()
            L.queue[-1] = s
        else: L.queue[-1]*=int(c)
    return sum(L.queue)
if __name__ == '__main__':
    for i in range(int(input())): print(hoachat(input()))
