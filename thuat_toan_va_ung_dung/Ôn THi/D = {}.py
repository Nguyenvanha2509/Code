import queue
if __name__=="__main__":
    n=int(input())
    a=map(int,input().slit())
    L = queue.PriorityQueue()
    R = queue.PriorityQueue()
    for i,x in enumerate(a,1):
        if i%2==1:
            L.put(-x)
        else:
            R.put(x) 
        if i>1 and -L.queue[0]>R.queue[0]:
            u,v = -L.get(),R.get()
            L.put(-v)
            R.put(u)
        print(-L.queue[0],end="")    
