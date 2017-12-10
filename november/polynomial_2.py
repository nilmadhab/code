T = input()

ar = []

def aux(t, ind):
	return ar[ind][0] + ar[ind][1]*t + ar[ind][2]*t*t + ar[ind][3]*t*t*t 

def compute( t ):

	mini = aux(t, 0)

	for i in xrange(1, len(ar)):
		mini = min(mini, aux(t, i))

	print mini

def compare(cof1, cof2):
	flag = True
	for i in xrange(4):
		if cof1[i] > cof2[i]:
			return True
	return False 


def isInsert(coff):

	for co in ar:
		if compare(co, coff) == False:
			return False 
	return True



for _ in range(T):
	ar = [] 
	highest = []
	n = input()
	for _ in range(n):
		coff = map(int, raw_input().split(" "))
		if isInsert(coff) == True:
			ar.append(coff)
	#print ar
	q = input()

	for _ in range(q):
		t = input()
		compute(t)
'''
if len(highest) == 0:
			highest = coff
			ar.append(coff)
		elif coff 
'''


