def fail():
    print("I hate UCPC")
    exit(0)
def succ():
    print("I love UCPC")
    exit(0)
s=input()
a=s.find("U")
if a==-1:fail()
b=s[a+1:].find("C")
if b==-1:fail()
c=s[a+b+1:].find("P")
if c==-1:fail()
d=s[a+b+c+1:].find("C")
if d==-1:fail()
succ()
