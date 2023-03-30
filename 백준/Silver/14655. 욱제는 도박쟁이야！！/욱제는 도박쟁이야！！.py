n=int(input())
r1=list(map(int,input().strip().split()))
r2=list(map(int,input().strip().split()))
print(sum(i if i>0 else i*-1 for i in r1)-sum(i if i<0 else i*-1 for i in r2))