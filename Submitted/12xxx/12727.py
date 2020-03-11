from decimal import *
import math
getcontext().prec = 200
getcontext().rounding = ROUND_DOWN

x = Decimal('3') + Decimal('5').sqrt()
a = int(input())
for i in range(1, a+1):
    b = int(input())
    print("Case #%d: %03d" % (i, (math.floor(pow(x, b))) % 1000))
