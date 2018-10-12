d={}
for i in range(2):
  ip=input("enter ip  : ")
  mac=input("enter mac : ")
  d[ip]=mac
print(d)
print()
s=input("enter search")
print(d[s])