# duong di ngan nhat trong me cung
from queue import Queue
n,m=map(int,input().split())
A=[]
A.append([1]*(m+2))
for i in range(n):
    a=list(map(int,input().split()))
    A.append([1]+a+[1])
A.append([1]*(m+2))
#for i in range(0,n+2):print(*A[i])
Q=Queue()
sx,sy,fx,fy=map(int,input().split())
A[sx][sy]=1
Q.put((sx,sy))
while Q.qsize() and A[fx][fy]==0:
    x,y=Q.get()
    for i,j in (-1,0),(1,0),(0,-1),(0,1):
        if A[x+i][y+j]==0:
            A[x+i][y+j]=A[x][y]+1
            Q.put((x+i,y+j))
print(A[fx][fy]-1)

