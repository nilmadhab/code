for _ in range(int(input())):
	a=input()
	if len(a)==2:
		if a[0]==a[1]:
			print(1)
		else:
			print(0)
	elif len(a)<2:
		print(0)
	else:
		i=1
		b=a[0]
		c=[]
		j=0
		a+="$"
		while i<len(a):
			if a[i] != b:
				c.append([j,i-1])
				b=a[i]
				j=i
				
			i+=1
		print(c)
		count=0
		
		
		for j in c:
			if j[0]>0 and a[j[0]-1] == a[j[1]+1] and (j[1]+1)<len(a):
				
				count+=1
			
			count+=(((j[1]-j[0])*(j[1]-j[0]+1))//2)
			
		print(count)