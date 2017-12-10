def compute(N, ar):
    
    i = 0 
    
    NUM_COUN = 0 
    dic = {}
    while ( i  < len(ar)):
        num = ar[i]
        NUM_COUN +=1
        dic[NUM_COUN] = num
        for j in range(i+1, i+num):
            if j >= len(ar) or ar[j] != num:
                return "Invalid Data"
        i += num

    S = 0
    for n in dic:
        S += dic[n]
    if S != N :
        return "Invalid Data"

        
    return NUM_COUN
    
    
    

T = input()
for _ in range(T):
    N = input()
    ar = map(int, raw_input().split(" "))
    print compute(N, ar)
    
