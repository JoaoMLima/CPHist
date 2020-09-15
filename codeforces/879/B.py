import Queue
N, K = map(int, raw_input().split())
A = map(int, raw_input().split())
Q = Queue.Queue()
if (K > N):
    print max(A)
else:
    B, W = A[0], 0
    for i in range(1, N):
        Q.put(A[i])
    while True:
        top = Q.get()
        if B > top:
            Q.put(top)
            W += 1
        else:
            Q.put(B)
            B, W = top, 1
        if W >= K:
            print(B)
            break