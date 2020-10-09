MOD = 1000000007

def MD(x): return ((x%MOD)+MOD)%MOD

s = raw_input()
res = 1
cnt = 1
for c in s:
	if c == 'a':
		cnt += 1
	elif c == 'b':
		res = MD(res*cnt)
		cnt = 1
res = MD(res*cnt)

print MD(res-1)