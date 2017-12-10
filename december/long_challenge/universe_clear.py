import math
from fractions import gcd
def sort(x, y , z):
	n = [x,y, z]
	n.sort()
	return (n[0], n[1], n[2])

def formula3D(a, b,c,  x, y, z):
	mygcd = reduce(gcd,(30,40,60))
	cost = 0 
	x,y,z = sort(x,y, z)
	#print x,y,z
	cost = formula(a, b,c,  x, y, z)
	cost = min(cost, c*x + formula(a,b,c, 0, y-x, z-x))
	#print formula(a,b, y-x, z-x)
	cost2 = float("Inf")
	if 2*c <= 3*b or c <= 3*a or c<= a+b :
		#mygcd = 1
		x /= mygcd
		y /= mygcd
		z /= mygcd
		for i in xrange(x+1):
			cost2 = min(cost2, c*(x-i) + formula(a,b,c, i, y-x+i, z-x+i) )
		cost2 *= mygcd
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




def take_input():
	T = input()
	for _ in xrange(T):
		x,y,z, a, b , c = map(int, raw_input().split(" "))
		if x > 500 or y > 500 or z > 500:
			return
		print formula3D(a, b, c, x, y , z)

take_input()

