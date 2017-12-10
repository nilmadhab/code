T = input()

for _ in xrange(T):
	N = input()

	ar = map(int, raw_input().split(" "))
	dic = {}
	for a in ar:
		if a in dic:
			dic[a] +=1
		else:
			dic[a] = 1 
	N = len(ar)

	if N == 1:
		print 0
		print ar[0]
	elif N == 2:
		if ar[0] == ar[1]:
			print 0
			print ar[0], ar[1]
		else:
			print 2
			print ar[1], ar[0]
	elif N == 3:
		if len(dic) == len(ar):
			print 3
			print ar[1], ar[2] , ar[0]
		else:
			#possibility
			# 0== 1, 0 == 2, 1 == 2
			print 2
			if dic[ar[0]] == 2:
				if ar[0] == ar[1]:
					print ar[2], ar[0], ar[1]
				else:
					print ar[1], ar[0], ar[2]
			else:
				# 1 and 2 are equal
				print ar[1], ar[0], ar[2]
	else:
		# more than 3
		print N
		lis = list(ar)
		lis_2=[]
		lis_1=[]
		dic2 = {}
		dic3 = {}
		for x in ar:
			if dic[x] == 1:
				lis_1.append(x)
			elif x not in dic2:
				lis_2.append(x)
				dic2[x] = 1
		if(len(lis_1) > 0 ):
			lis_1 = [lis_1[len(lis_1) - 1 ] ] + lis_1[:-1]
		if len(lis_2) > 0 :
			lis_3 = [lis_2[len(lis_2) - 1 ] ] + lis_2[:-1]
			for i in xrange(len(lis_2)):
				dic3[lis_2[i]] = lis_3[i]

		ind0 = 0
		ind1 = 0
		for i in xrange(len(ar)):
			if dic[ar[i]] == 1:
				lis[i] = lis_1[ind0]
				ind0 +=1 
			else:
				lis[i] = dic3[ar[i]]
			
		if len(lis_1) == 1:
			#print "list 1"
			ind0 = 0
			ind1 = 0
			index = 0 
			for i in xrange(len(ar)):
				if dic[ar[i]] == 1:
					index = i 
				else:
					lis[i] = dic3[ar[i]]
			
			if index > 0:
				lis[index], lis[index-1] = lis[index-1], lis[index]
			else:
				lis[index], lis[index+1] = lis[index+1], lis[index]
			

		elif len(lis_2) == 1:
			#print "list 2"
			ind0 = 0
			ind1 = 0
			index1 = -1 
			index2 = -1
			replace1 = -1 
			replace2 = -1 
			for i in xrange(len(ar)):
				if dic[ar[i]] == 1:
					lis[i] = lis_1[ind0]
					ind0 +=1 
					if replace1 == -1:
						replace1 = i 
					elif replace2 == -1:
						replace2 = i 
				else:
					if index1 == -1:
						index1 = i 
					elif index2:
						index2 = i 
			#print index1, index2, replace1, replace2
			lis[index1], lis[replace1] = lis[replace1], lis[index1]

			lis[index2], lis[replace2] = lis[replace2], lis[index2]

			
		'''
		for x in ar:
				print x,
		print "" 	
		'''	
		for x in lis:
			print x,
		print "" 










