def functiona(first, rest):
	x = [first]
	for n in range(len(rest)):
		x.append(rest[n])
	return x

print(functiona(1, [2,3,4]))
