def inSort(L):
	for n in range(1, len(L)):
		v = n
		k = L[n]
		for j in range(n-1, -1, -1):
			if k >= L[j]:
				L[v] = k
				break
			L[v] = L[j]
			v = j
			if v == 0:
				L[v] = k
				break
	return L

print(inSort([2,6,3,1,7,4,9,2]))
