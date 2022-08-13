a,b=map(int,input().split())
if (a,b)==(0,0):
    print("Not a moose")
elif a==b:
    print("Even",a*2)
else:
    print("Odd",max(a,b)*2)