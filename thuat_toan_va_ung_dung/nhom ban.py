from queue import LifoQueue

import queue

class Friend:
    def nhap(self):
        self.n,self.m=map(int,input().split())
        self.A=[[] for i in range(self.n+2)]
        for i in range(self.m):
            x,y=map(int,input().split())
            self.A[x].append(y)
            self.A[y].append(x)
        self.d=[0]*(self.n+5)
        self.res=0
        self.g=0
    def Tim(self,k,Q): #tra ve so ptu cua nhom chua k
        Q.put(k)
        dem=1
        self.d[k]=1
        while Q.qsize():
            u=Q.get()
            for v in self.A[u]:
                if self.d[v]==0:
                    self.d[v]=1
                    dem+=1
                    Q.put(v)

        return dem
    def sol(self):
        #self.nhap()
        #for i in range(1,self.n+1):
        #    print(1,end=" : ")
        #    print(*self.A[i])

        #Q=queue.Queue() # ->BFS
        Q=queue.LifoQueue()   #-> DFS
        for i in range(1,self.n+1):
            if self.d[i]==0:
                self.g+=1
                self.res=max(self.res,self.Tim(i,Q))
        print(self.g,self.res,sep="\n")        

if __name__=="__main__":
    F=Friend()
    F.nhap()
    F.sol()



