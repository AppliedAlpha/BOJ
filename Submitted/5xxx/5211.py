str = input().split('|')
c = 0
a = 0
for i in range(len(str)):
    if str[i][0] == 'C' or str[i][0] == 'F' or str[i][0] == 'G':
        c += 1
    if str[i][0] == 'A' or str[i][0] == 'D' or str[i][0] == 'E':
        a += 1

if c > a:
    print("C-major")
elif c < a:
    print("A-minor")
else:
    t = len(str)-1
    if str[t][len(str[t])-1] == 'C':
        print("C-major")
    else:
        print("A-minor")
