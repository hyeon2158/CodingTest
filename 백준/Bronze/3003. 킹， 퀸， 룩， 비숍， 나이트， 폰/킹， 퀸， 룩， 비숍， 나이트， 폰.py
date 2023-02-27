exist = [1, 1, 2, 2, 2, 8]
l = list(map(int, input().split()))
for i in range(6):
    print(exist[i]-l[i], end=" ")