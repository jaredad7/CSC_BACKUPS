#Verify 1+2+3+...+n = n*(n+1)/2
#Change n to verify for different values

n=5
x=0
for i in range(n+1): x += i
print(x)
x = int(n*(n+1)/2)
print(x)
