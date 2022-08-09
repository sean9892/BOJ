r = int(input())
for _ in range(int(input())):
    a,b=map(int,input().split())
    r-=a*b
print(["Yes","No"][r!=0])