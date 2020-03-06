from decimal import *
getcontext().prec = 200
getcontext().rounding = ROUND_HALF_UP

pi = Decimal('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116')


def sin(x):
    """Return the sine of x as measured in radians.

    The Taylor series approximation works best for a small value of x.
    For larger values, first compute x = x % (2 * pi).

    From docs.python.org/3/library/decimal.html#decimal-recipes
    """
    x = x % (2 * pi)
    i, lasts, s, fact, num, sign = Decimal('1'), Decimal('0'), Decimal(x), Decimal('1'), Decimal(x), Decimal('1')
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    return Decimal(s)


a, b, c = map(Decimal, input().split())
min = Decimal('0')
max = Decimal('500000')
diff = Decimal('1.0e-60')
mid = Decimal((min + max) / 2)
while (Decimal(max - min).copy_abs()) >= diff:
    mid = Decimal((min + max)/2)
    if Decimal(a*mid + b*sin(mid)) >= Decimal(c):
        max = mid
    else:
        min = mid

print(round(mid, 6))