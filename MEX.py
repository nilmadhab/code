T = input()

def aux(ar,K):

	dic = {}

	for x in ar:
		dic[x] = 1 

	N = 200000

	count = 0 

	ind = 0 

	while ind < N and count <= K:
		if not ind in dic:
			dic[ind] = 1
			count +=1 
		ind += 1 

	print ind 


for _ in range(T):
	N,K = map(int, raw_input().split(" "))
	ar = map(int, raw_input().split(" "))
	sort(ar)
	aux(ar,K)