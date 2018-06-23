#Reduces a set into a list of its subsets

def subsets(inset):
	outset=[()]
	for x in range(0, len(inset)):
		s=[(inset[x])]
		for y in range(0, len(outset)):
			outset.append(set(s) | set(outset[y]))
	return outset
print(subsets([1,2,3,4]))
