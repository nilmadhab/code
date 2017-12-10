import math
from fractions import gcd
a = 3
b = 5
c = 6
x = 5
y = 15

def dynamic(a, b, x, y):
	dp = [[float('inf') for _ in range(y+1)] for _ in range(x+1)]
	dp[0][0] = 0 
	for i in range(x+1):
		for j in range(y+1):
			if i-1 >= 0:
				dp[i][j] = min(dp[i][j] , dp[i-1][j]+a)
			if j-1 >= 0 :
				dp[i][j] = min(dp[i][j], dp[i][j-1]+a)
			if i-1 >= 0 and j-1 >= 0 :
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+b)

	return dp[x][y]

def print_dp(dp, x, y, z):
	for i in range(x+1):
		for j in range(i, y+1):
			for k in range(j, z+1):
				print dp[i][j][k], "(" , i, j , k , ")"
			print ""
		print " "

def dynamic3D(a, b, c,  x, y, z):
	dp = [ [ [float('inf') for _ in range(z+1)] for _ in range(y+1) ] for _ in range(x+1)]
	dp[0][0][0] = 0 
	MAX = 10
	count = 0
	for i in range(x+1):
		for j in range(i, y+1):
			for k in range(j, z+1):

				if(i-1 >= 0):
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+a);
				if(j-1 >=0 ):
					dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]+a);
				if(k-1 >=0 ):
					dp[i][j][k] = min(dp[i][j][k], dp[i][j][k-1]+a);
				
				if(i-1 >= 0 and j-1 >= 0 ):
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k]+b);
				
				if(j-1 >=0 and k-1 >= 0 ):
					dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k-1]+b);
			  
				if(k-1 >=0 and i-1 >= 0):
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k-1]+b);
				
				if(i-1 >= 0 and j-1 >= 0 and k-1 >= 0):
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k-1]+c);

				if dp[i][j][k] != formula3D(a, b, c, i , j , k):
					print dp[i][j][k], "(" , i, j , k , a, b, c, ")" , formula3D(a, b, c, i , j , k), "#############################"
					count +=1
					#if(count > MAX):
						#return
	print_dp(dp, x, y, z)
	
	return dp[x][y][z]

def sort(x, y , z):
	n = [x,y, z]
	n.sort()
	return (n[0], n[1], n[2])

def getCostByBinarySearch(a, b,c,  x, y, z):

	start = 0
	end = x 
	def getCost(ind):
		return formula(a,b,c, ind, y-ind, z-ind)

	while(start <= end):
		mid = (start + end)/2 
		if(getCost(start) <= getCost(mid) ):
			end = mid-1
		else:
			start = mid+1 

	return start




def formula3D(a, b,c,  x, y, z):
	mygcd = reduce(gcd,(30,40,60))

	cost = 0 
	x,y,z = sort(x,y, z)
	#print x,y,z
	cost = formula(a, b,c,  x, y, z)
	#cost = min(cost, c*x + formula(a,b,c, 0, y-x, z-x))
	#print formula(a,b, y-x, z-x)
	cost2 = float("Inf")

	if 2*c <= 3*b or c <= 3*a or c<= a+b :
		mygcd = 1
		x /= mygcd
		y /= mygcd
		z /= mygcd
		cost_check = float("Inf")
		cost_x = 0	
		for i in xrange(x+1):
			cost2 = min(cost2, c*(x-i) + formula(a,b,c, i, y-x+i, z-x+i) )
			print i, c*(x-i) + formula(a,b,c, i, y-x+i, z-x+i), " i and cost"
			if cost2 < cost_check:
				cost_check = cost2
				cost_x = i 
		cost2 = mygcd*cost2
		if cost_check <= cost:
			print getCostByBinarySearch(a,b,c, x, y , z), " binary search ",  cost_x, cost_check, "cost_x, cost_check", "(" , x, y , z , a, b, c, ")" , "x-i", x-cost_x
	return min(cost, (x+y+z)*a, cost2)

def formula(a, b, c, x, y, z):
	cost = 0
	if z >= x+y:
		cost = (x+y)*b + (z-x-y)*a
	elif (x+y+z)%2 == 0:
		cost = (x+ y + z)/2*b
	else:
		cost = (x+ y + z-1)/2*b + a 

	return min(cost, a*(x+y+z)) 

def formula2D(a, b, c, x, y, z):
	cost = 0
	if z >= x+y:
		cost = (x+y)*b + (z-x-y)*a
	elif (x+y+z)%2 == 0:
		cost = (x+ y + z)/2*b
	else:
		cost = (x+ y + z-1)/2*b + a 

	return cost 

	


def check3D():
	for a in range(1, 10):
		for b in range(1, 10):
			for c in range(1, 10):
				for i in xrange( 10, 11):
					for j in range(10, 11):
						for k in range(10, 11):
							dynamic3D(a, b, c,  i, j, k )
								#return

#
'''
check3D()
#print formula3D(1, 1, 2, 1, 1 , 2)
print dynamic3D(1, 1, 2, 2, 2 , 2)
'''

a = 34
b = 45
c = 50
i = 499
j = 601
k = 810
#print dynamic3D(a, b, c, i, j , k)
print formula3D(a, b, c, i, j , k)
#'''

'''
for i in xrange( 1, 10):
	for j in range(1, 10):
		for k in range(1, 10):
			print dynamic3D(a, b, c, i, j , k),  "(" , i, j , k , ")" 
'''
def take_input():
	T = input()
	for _ in xrange(T):
		x,y,z, a, b , c = map(int, raw_input().split(" "))
		if x > 500 or y > 500 or z > 500:
			return
		print formula3D(a, b, c, x, y , z)

#take_input()
#check3D()
