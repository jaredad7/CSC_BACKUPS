#Write a binary search
def binSearch(arr, first, last, K):
	if last < first:
		index = -1
	else:
		mid = int((first+last)/2)
		if K == arr[mid]:
			index = mid
		elif K < arr[mid]:
			index = binSearch(arr, first, mid-1, K)
		else:
			index = binSearch(arr, mid+1, last, K)
	return index

print(binSearch([1,2,3,4,5,6,7,8,9], 0, 8, 6))
