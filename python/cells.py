"""
 *Calculate the probability of the first
 *cell to self-replicate coming into existence
 *by random placement of base-pairs.
 *Note that this is the probability for a single
 *try and not for a cumulative number of tries.
 *This also assumes only one possible combination
 *of base-pairs contains the function to 
 *self-replicate.
 *
 *@author<Jared Dembrun>
 *@date<2/8/14>
"""

SIZE_NEEDED = 108
BASE = 2
value = 2
i = 1

while i != SIZE_NEEDED:
	value = (BASE*value)
	i += 1
print(value)
