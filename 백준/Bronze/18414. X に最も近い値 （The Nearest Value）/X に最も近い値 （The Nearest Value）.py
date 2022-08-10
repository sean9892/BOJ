a,b,c=map(int,input().split())
print(min([(abs(a-b),b),(abs(a-c),c),((1-int(b<=a<=c))*99999999999,a)])[1])