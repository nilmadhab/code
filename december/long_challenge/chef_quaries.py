T = input()
tree = {}
values = {}
MOD = pow(10, 9) + 7

def compute(v, k, a, b):
    #print v, k, a, b, "v, k, a, b," 
    lis = [v]
    dis = 0 
    visited = {}
    visited[v] = 0 
    dis_lis = [a, b]
    for x in xrange(2, k+1):
        dis_lis.append( (dis_lis[x-1] + dis_lis[x-2]) % MOD )
    dis_map = {}
    dis_map[v] = 0
    while len(lis) > 0 :
        pop = lis.pop(0)
        if dis_map[pop] <= k:
            values[pop] += dis_lis[dis_map[pop]]
            values[pop] %= MOD
        for u in tree[pop]:
            if not u in visited:
                dis_map[u] = dis_map[pop]+1
                if dis_map[u] <= k:
                    lis.append(u)

    #print visited, " visited"
    #print dis_lis , " dis_lis "
    #print values , " values"
    #dis +=1;
    #print pop, dis , " pop, dis "
    #dis_lis.append( (dis_lis[len(dis_lis)-2] + dis_lis[len(dis_lis)-1] )%MOD )

for _ in xrange(T ):
    N, Q = map(int, raw_input().split(" "))
    tree = {}
    values = {}
    for i in xrange(1,N+1):
        tree[i] = {}
        values[i] = 0
    for _ in xrange(N-1):
        u, v = map(int, raw_input().split(" "))
        tree[u][v] = 1
        tree[v][u] = 1
    #print tree
    for q in xrange(Q):
        ar = map(int, raw_input().split(" "))
        if ar[0] == 1:
            v, k, a, b = ar[1], ar[2], ar[3], ar[4]
            compute(v, k, a, b)
        else:
            v = ar[1]
            print values[v]%MOD #, v, " values[v] ##################"




