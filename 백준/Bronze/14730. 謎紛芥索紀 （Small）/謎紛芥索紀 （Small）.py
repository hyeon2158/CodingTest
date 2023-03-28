n=int(input())
total=0
for _ in range(n):
    c, k = map(int, input().split())
    total += c*k
print(total)