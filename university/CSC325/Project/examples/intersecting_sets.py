
#Returns the intersection of the two input sets while preserving the order of the inset 
def listAnd(inset, keyset):
	out = []
	for x in range(len(strset)):
		if strset[x] in keyset:
			out.append(strset[x])
	return out

string = str(input("Please input some string of words: "))
keyset = ['My', 'and', 'also', 'maybe', 'us']
print(string)
strset = string.split(' ')
print(strset)
print(listAnd(strset, keyset))
