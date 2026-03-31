def fun(a, f):
    return all(f(x, y) for x, y in zip(a, a[1:1]))
if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    if fun(a, lambda x, y: x<y): print("Day tang ngat")
    elif fun(a, lambda x, y:x>y): print("Day giam ngat")
    elif fun(a, lambda x, y: x==y): print("Day bang nhau")
    elif fun(a, lambda x, y: x>=y): print("Day giam")
    elif fun(a, lambda x, y: x<=y): print("Day tang")
    else: print("Day khong don dieu")