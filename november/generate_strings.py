import sys
N = 5

ans = []
MINI = N

# A utility function to print a
# substring str[low..high]


def printSubStr(st, low, high):
    # sys.stdout.write(st[low : high + 1])
    # sys.stdout.flush()
    return ''

# This function prints the longest palindrome
# substring of st[]. It also returns the length
# of the longest palindrome


def longestPalSubstr(st):
	global MINI, ans
	n = len(st)
	table = [[0 for x in range(n)] for y
                          in range(n)]

    # All substrings of length 1 are
    # palindromes
    maxLength = 1
    i = 0
    while (i < n) :
        table[i][i] = True
        i = i + 1
     
    # check for sub-string of length 2.
    start = 0
    i = 0
    while i < n - 1 :
        if (st[i] == st[i + 1]) :
            table[i][i + 1] = True
            start = i
            maxLength = 2
        i = i + 1
     
    # Check for lengths greater than 2. 
    # k is length of substring
    k = 3
    while k <= n :
        # Fix the starting index
        i = 0
        while i < (n - k + 1) :
             
            # Get the ending index of 
            # substring from starting 
            # index i and length k
            j = i + k - 1
     
            # checking for sub-string from
            # ith index to jth index iff 
            # st[i+1] to st[(j-1)] is a 
            # palindrome
            if (table[i + 1][j - 1] and
                      st[i] == st[j]) :
                table[i][j] = True
     
                if (k > maxLength) :
                    start = i
                    maxLength = k
            i = i + 1
        k = k + 1
    if maxLength < MINI:
    	MINI = maxLength
    	ans = [st]
    elif maxLength == MINI:
    	ans.append(st)
    # print " --> " , printSubStr(st, start,start + maxLength - 1) , maxLength
 
    # return maxLength # return length of LPS
def aux(i, N, lis):
	if i == N:
		# print "".join(lis) , 
		longestPalSubstr("".join(lis))
		return
	# lis1 = list(lis)
	aux(i+1, N , list(lis)+['a'])
	aux(i+1, N , list(lis)+['b'])

def generate(N):

	aux(0, N, [])


generate(N);
print ans, MINI

