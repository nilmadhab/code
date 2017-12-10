N1, N2, N3 = map(int, raw_input().split(" "))

ar1 = []
ar2 = []
ar3 = []

dic = {}

for x in xrange(N1):
	a = input()
	ar1.append(a)
	dic[a] = 1 + dic.get(a, 0);

for x in xrange(N2):
	a = input()
	ar2.append(a)
	dic[a] = 1 + dic.get(a, 0);

for x in xrange(N3):
	a = input()
	ar3.append(a)
	dic[a] = 1 + dic.get(a, 0);
res = []
for x in dic:
	if dic[x] >= 2:
		res.append(x)
res.sort()
print len(res)
for r in res:
	print r 

() (()) () (()()) (()())
