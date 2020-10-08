n = int(raw_input())
mini = []
maxi = []
asc = 0
nasc = 0
for index in xrange(n):
	s = map(int, raw_input().split())[1:]
	na = True
	for i in xrange(len(s)):
		if i > 0 and s[i] > s[i-1]:
			na = False
			break
	if na:
		nasc += 1
		mini.append(min(s))
		maxi.append(max(s))
	else:
		asc += 1
total = asc*asc
total += 2*asc*nasc
mini.sort()
maxi.sort()
i = 0
for x in maxi:
	while i < nasc and mini[i] < x:
		i += 1
	total += i

print(total)