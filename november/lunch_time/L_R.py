
T = input()

for _ in range(T):
	N,Q = map(int, raw_input().split(" "))

	lis = map(int, raw_input().split(" "))
	#print lis
	for x in xrange(Q):
		ty, a, b = map(int, raw_input().split(" "))

		if(ty == 1):
			maxi = 0
			for x in xrange(a-1, b):
				maxi = max(maxi, (lis[x] - lis[a-1])*(lis[b-1]-lis[x]) )
			print maxi 
		else:
			lis[a-1] = b
