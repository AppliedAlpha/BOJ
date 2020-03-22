"""
from decimal import *
getcontext().rounding = ROUND_CEILING
a = int(input())
for i in range(a):
    getcontext().prec = 1000
    v = round(Decimal(input()) ** (Decimal('1')/Decimal('3')), 500)
    v *= Decimal(10 ** 10)
    print(f'{Decimal(Decimal(int(v)) / 10 ** 10):.10f}')

# Working.
"""
