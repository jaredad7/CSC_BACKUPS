#Sort an array into an order
def sort(arr):
	for x in range(len(arr)): 
		for y in range(x):
			if arr[y] > arr[x]:
				temp = arr[y]
				arr[y] = arr[x]
				arr[x] = temp
	return arr
