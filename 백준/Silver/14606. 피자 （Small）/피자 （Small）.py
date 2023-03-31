import sys
input = sys.stdin.readline

Num=int(input())

if Num==1:
    print(0)
    exit(0)
    
print(Num*(Num-1)//2)