#Search an unordered array
def search(x, arr):
	for i in range(len(arr)):
		if x == arr[i]:
			return i
	return -1

print(search(1, [2,4,9,5,8,1,0]))4
