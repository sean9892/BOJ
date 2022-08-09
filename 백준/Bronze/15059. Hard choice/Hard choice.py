a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
print(sum(max(0,y-x)for x,y in zip([a,b,c],[d,e,f])))