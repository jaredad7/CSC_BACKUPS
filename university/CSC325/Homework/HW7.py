#Returns a set of highest and lowest values in an input set
#Index 0 is highest. Index 1 is lowest.
def minmax(arr):
	#If an odd length exists, put the last digit in the side array
	side = []
	if(len(arr) % 2):
		side = [arr.pop()]

	#Split the array into winners and losers
	win = []
	lose = []
	for x in range(0, len(arr), 2):
		if(arr[x] >= arr[x+1]):
			win.append(arr[x])
			lose.append(arr[x+1])
		else:
			win.append(arr[x+1])
			lose.append(arr[x])

	#Handle the win set. All who lose must be removed.
	while not(len(win) == 1):
		if(win[0] >= win[1]):
			win.pop(1)
		else:
			win.pop(0)

	#Handle the lose set. All who win must be removed
	while not(len(lose) == 1):
		if(lose[0] >= lose[1]):
			lose.pop(0)
		else:
			lose.pop(1)

	#Compare side to the two values if necessary.
	if(len(side)):
		if(side[0] >= win[0]):
			return [side[0], lose[0]]
		elif(side[0] <= lose[0]):
			return [win[0], side[0]]
	return [win[0], lose[0]]

#[781, 1]
print(minmax([63,21,47,89,1,3,9,10,456,789,243,567]))
