

all_list = []

def generate(lis, ind, N, left, right):
	#print lis,  ind, N, left, right
	if ind == N:
		all_list.append("".join(lis));
		return
	if left < N/2:
		lis2 = lis[:]
		lis2.append( "(")
		generate(lis2, ind+1, N, left+1, right)
	if right < left:
		lis2 = lis[:]
		lis2.append( ")" )
		generate(lis2, ind+1, N, left, right+1)


generate([], 0, 2*4, 0, 0)

print all_list
