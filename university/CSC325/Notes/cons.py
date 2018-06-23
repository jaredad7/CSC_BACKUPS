def cons(newElem, oldList):
	return [newElem]+oldList[:]

def first(aList):
	return aList[0]

def rest(aList):
	return aList[1:]

def nil(aList):
	return len(aList)==0

def delete(L, x):
	if(nil(L)):
		newL = L
	elif(x == first(L)):
		newL = rest(L)
	else:
		fixedL = delete(rest(L), x)
		newL = cons(first(L), fixedL)
	return newL

def reverse(L, NL=[]):
	if(not nil(L)):
		return reverse(rest(L), cons(first(L), NL))
	else:
		return(NL)

print(reverse([1,2,3]))
