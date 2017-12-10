
N = input()

ar = []

for x in xrange(N):
	a,b = map(int, raw_input().split(" "))

	if a > b:
		ar.append(b)
	else:
		ar.append(a)

ar.sort()

#print ar 

ans = 0

dim = 1

for a in ar:
	if a >= dim:
		ans +=1 
		dim +=1

print ans