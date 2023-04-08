import sys
input = sys.stdin.readline

for i in range(int(input())):
    V,E = map(int,input().split())
    print(E-V+2)