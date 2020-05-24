a = list(map(int, input().split()))
st = ""
if len(str(a[0]))*a[0] >= a[1]:
    while len(st) <= a[1]:
        st += str(a[0])
    print(st[:a[1]])
else:
    for i in range(a[0]):
        st += str(a[0])
    print(st)
