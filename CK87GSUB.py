

T = input()

def verify(s):

	if len(s) == 2 and s[0] == s[1]:
		return True

	if len(s) > 2 and s[0] == s[len(s) - 1] :

		dic = {}

		for c in s[1:-1]:

			if len(dic) > 1:
				return False
			else:
				dic[c] = 1 

		return True 

	return False

def process(s):

	N = len(s)

	dp = [ [False for i in range(N)] for j in range(N) ]
	count = 0;
	for i in range(N-2, -1, -1):
		for j in range(i+1, N):
			#check if S[i:j] is valid
			if s[i] == s[j]:
				if j == i+1 or j == i+2:
					dp[i][j] = True 
					count +=1
				elif dp[i+1][j-1] == True and s[i+1] == s[i+2]:
					dp[i][j] = True
					count +=1
	#for x in dp:
		#print x 
	return count







for _ in range(T):
	s = raw_input()
	print process(s) 
