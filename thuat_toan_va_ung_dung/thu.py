from queue import LifoQueue

def ngoac(x):
    L = LifoQueue()
    D = {'{': 3, '[': 2, '(': 1, '}': 3, ']': 2, ')': 1}
    C = {'{': '}', '[': ']', '(': ')'}
    
    for c in x:
        if c in C:  # dấu mở
            if L.qsize() and D[L.queue[-1]] < D[c]:
                return "sai"
            L.put(C[c])
        elif c in C.values():  # dấu đóng
            if L.empty() or L.queue[-1] != c:
                return "sai"
            L.get()
    
    return "Dung" if L.empty() else "sai"

if __name__ == '__main__':
    for i in range(int(input("Số test: "))):
        print(ngoac(input("Chuỗi ngoặc: ")))
