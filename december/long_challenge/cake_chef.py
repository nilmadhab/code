T = input()


def compute(ar):

    cost1 = 0

    for i in range(len(ar)):
        if i%2 == 0:
            #RGRGRG
            #GRGRGR
            for j in range(len(ar[i])):
                if j% 2 == 0 and ar[i][j] == 'G':
                    cost1 += 3
                elif j % 2 == 1 and ar[i][j] == 'R':
                    cost1 += 5 
        else:
            for j in range(len(ar[i])):
                if j% 2 == 0 and ar[i][j] == 'R':
                    cost1 += 5
                elif j % 2 == 1 and ar[i][j] == 'G':
                    cost1 += 3 

    cost2 = 0
    for i in range(len(ar)):
        if i%2 == 0:
            #GRGRGRG
            #RGRGRGR
            for j in range(len(ar[i])):
                if j% 2 == 0 and ar[i][j] == 'R':
                    cost2 += 5
                elif j % 2 == 1 and ar[i][j] == 'G':
                    cost2 += 3 
        else:
            for j in range(len(ar[i])):
                if j% 2 == 0 and ar[i][j] == 'G':
                    cost2 += 3
                elif j % 2 == 1 and ar[i][j] == 'R':
                    cost2 += 5
    print min(cost1, cost2) 


for _ in xrange(T ):
    N, M = map(int, raw_input().split(" "))
    ar=[]
    for _ in xrange(N):
        ar.append(raw_input())
    compute(ar)


