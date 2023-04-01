import sys
input = sys.stdin.readline

num = int(input())
answer = 0

for i in range(1,num+1):
  if(num % i == 0):
    answer += i

print(answer)