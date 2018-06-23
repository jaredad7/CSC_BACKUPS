#Insertion Sort
#Has some weird bug; only works for numbers >= 1.
def insertion(arr):
	for i in range(1,len(arr)):
		m = arr[i]
		for x in range(i-1,-1,-1):
			if(arr[x] > m):
				arr[x+1] = arr[x]
			else:
				arr[x+1] = m
				break
	return arr

l1 = [1,3,7,2,5,8,4,6]
l2 = [1.1,3.7,7.0,2.5,5.1,8.3,4.0,7.9,6.0]
l3 = [1,3,7,2,5,8,0,4,6]
l4 = [1.1,3.7,7.0,2.5,5.1,8.3,4.0,7.9,6.0,0.3]
print(insertion(l1))
print(insertion(l2))
print(insertion(l3))
print(insertion(l4))
