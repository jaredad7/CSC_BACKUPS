#Jared Dembrun
#Create a function which, for a given set, will return all subsets of that set

import itertools
import sys

def findsubsets(S):
	ret={()}
	for i in range(0, len(S)+1):
		ret = (ret | set(itertools.combinations(S, i)))
	return ret

print(findsubsets([1,2,3]))

