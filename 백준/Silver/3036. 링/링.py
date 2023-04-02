n = int(input())
radian = list(map(int, input().split()))
    
for i in range(n - 1):
    x = radian[0]
    y = radian[i+1]
    while(x % y != 0):
        r = x % y
        x = y
        y = r
    denominator = radian[0] // y    
    numeric = radian[i+1] // y   
    print(f'{denominator}/{numeric}')