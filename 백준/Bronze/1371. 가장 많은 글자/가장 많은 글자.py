import sys
s = sys.stdin.read()
w = [0]*26
for i in s:
    if i.islower():
        w[ord(i)-97] += 1
for i in range(26):
    if w[i] == max(w):
        print(chr(i+97), end="")