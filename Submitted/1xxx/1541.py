a = list(input().split('-'))
# print(a)
c = []

for st in a:
    b = st.split('+')
    t = 0
    for i in b:
        t += int(i)
    c.append(t)

res = 0
for i in range(len(c)):
    if i == 0:
        res += c[i]
    else:
        res -= c[i]

print(res)
