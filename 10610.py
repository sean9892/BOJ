s=input()
t=sum(map(int,s))
v=s.find('0')
if v==-1 or t%3:
    print(-1)
else:
    print(''.join(sorted(s)[::-1]))
