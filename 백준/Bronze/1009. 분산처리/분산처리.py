Testcase = int(input())
 
for _ in range(Testcase):
    a, b = map(int, input().split())
    result = pow(a, b, 10)
    if not result:
        print(result+10)
    else:
        print(result)