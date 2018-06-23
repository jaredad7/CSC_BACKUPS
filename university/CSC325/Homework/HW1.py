#For 0-9, create a set.
#Then, for each one, print out the factorial value
s={x for x in range(10)}
print(s)
for x in s:
	y=1
	while x > 0:
		y*=x
		x=x-1
	print(y)
