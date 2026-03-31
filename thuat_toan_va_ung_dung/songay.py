def nhuan(y):
    return y%400==0 or (y%4==0 and y%100!=0)

def songay(d, m, y):
    s = sum(365+nhuan(i) for i in range(1, y))
    t=[0, 31, 28+nhuan(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    return s+sum(t[:m])+d
if __name__ == '__main__':
    d1, m1, y1 = map(int, input().split())
    d2, m2, y2 = map(int, input().split())
    print(songay(d2, m2, y2) - songay(d1, m1, y1))