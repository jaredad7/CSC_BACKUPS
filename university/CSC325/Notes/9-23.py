#More stuff we can do with python
prime=[x for x in range(2,1000) if all([x%y for y in range(2,x-1)])]
print("A list of prime numbers")
print(prime)
print("\n")
print("Search an array for value K")
arr=list(range(20))
k=5
print(arr)
print(k)
print(k in arr)
print("Where in the function is the value?")
print(arr.index(k))
print("\n")
print("Associating else with for loop")
arr=list(range(20,30))
for x in range(len(arr)):
	if 24==arr[x]:
		print(x)
		break
else:
	print(-1)

for x in range(len(arr)):
	if 6==arr[x]:
		print(x)
		break
else:
	print(-1)
print("\n")
