from queue import LifoQueue

def ngoac(x):
    L=LifoQueue()
    D={'{':3,'[':2,'(':1,'}':3,']':2,')':1}
    C={'{':'}','[':']','(':')'}
    for c in x:
        if c in C.keys():
            if L.qsize() and D[L.queue[-1]] <D[c]:return "Sai"
            L.put(C[c])
        elif c in C.values():
            if L.empty() or L.queue[-1]!=c:return "Sai"
            L.get()

    return "Dung" if L.empty() else "Sai"

if __name__=='__main__':
    for i in range(int(input())): print(ngoac(input()))

