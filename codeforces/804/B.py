mod = 1000000007
qtdb = 0
jogadas = 0

s = raw_input()
for i in xrange(len(s)-1, -1, -1):
    if s[i] == 'b':
        qtdb = (qtdb + 1) % mod
    else:
        jogadas = (jogadas + qtdb) % mod
        qtdb = (2 * qtdb) % mod

print jogadas