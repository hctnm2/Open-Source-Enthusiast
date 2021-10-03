line = int(input())
print(line * "* ")
for i in range(line-2,0,-1):
    print((line-i-1)* " " +  "*" + (2*i -1)*" " + "* ")
print((line-1 )* " " + "* ")