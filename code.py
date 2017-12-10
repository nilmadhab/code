#code

N, H = map(int, raw_input().split(" "))
ar = map(int, raw_input().split(" "))
cmds = map(int, raw_input().split(" "))
currPos = 0
is_holding = False
for c in cmds:
    if c == 0:
        break
    if c == 1:
        #left
        if currPos > 0:
            currPos -= 1 

    elif c == 2:
        #right
        if currPos < N-1:
            currPos +=1 
    elif c == 3:
        #up
        if is_holding == False and ar[currPos] > 0 :
            ar[currPos] -= 1 
            is_holding = True

    elif c == 4:
        #drop
        if is_holding == True and ar[currPos] < H:
            ar[currPos] +=1 
            is_holding = False

for x in ar:
    print x,
print " "
