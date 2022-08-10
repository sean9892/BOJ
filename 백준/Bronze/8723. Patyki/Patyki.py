a,b,c=map(int,input().split())
if a==b and b==c:
    print(2)
elif a**2+b**2+c**2-max([a,b,c])**2==max([a,b,c])**2:
    print(1)
else:
    print(0)