import sys

n = int(sys.stdin.readline())
arr = []
dp = []
for i in range(n):
    tmp = []
    for j in range(n):
        tmp.append(0)
    dp.append(tmp)

for i in range(n):
    tmparr = [int(x) for x in sys.stdin.readline().split()]
    arr.append(tmparr)

dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            continue
        if i + arr[i][j] < n:
            dp[i + arr[i][j]][j] += dp[i][j]
        if j + arr[i][j] < n:
            dp[i][j + arr[i][j]] += dp[i][j]

print(dp[n-1][n-1])
