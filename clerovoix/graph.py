



def distance(source, dest, graph):
	if (not source in graph) or (not dest in graph):
		return -1 





N,M , k , x = map(int, raw_input().split(" "))

choco = map(int, raw_input().split(" "))

dic = {}

for i in range(1,N+1):
    dic[i] = {}

for i in range(M):
    u,v,d = map(int, raw_input().split(" "))
    dic[u][v] = d 
    dic[v][u] = d 
A,B = map(int, raw_input().split(" "))

print dic , choco, A,B 
    



