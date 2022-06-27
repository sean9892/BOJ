s = input()

# digits count of [1,n]
def digits(n):
    if n==0:
        return 0
    if n<10:
        return n
    if n<100:
        return 9+(n-9)*2
    return 189+3*(n-99)

for AL in range(1,4):
    a = int(s[:AL])
    for b in range(a,1000):
        if digits(b)-digits(a-1) == len(s) and s[::-1].startswith(str(b)[::-1]):
            print(a,b)
            exit(0)