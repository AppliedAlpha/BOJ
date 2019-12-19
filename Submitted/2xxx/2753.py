a = int(input())
print("1" if not a % 400 else "0" if not a % 100 else "1" if not a % 4 else "0")