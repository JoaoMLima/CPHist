from collections import deque
a, b = map(int, raw_input().split(" "))
pre = {}
fila = deque([a])
while fila:
	v = fila.popleft()
	if 2*v not in pre and 2*v <= b:
		fila.append(2*v)
		pre[2*v] = v
	if 10*v+1 not in pre and 10*v+1 <= b:
		fila.append(10*v+1)
		pre[10*v+1] = v

seq = [b]
if b not in pre:
	print "NO"
else:
	print "YES"
	x = b
	while x != a:
		x = pre[x]
		seq.append(x)
	print len(seq)
	for i in seq[::-1]:
		print(i),