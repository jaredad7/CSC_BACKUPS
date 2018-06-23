c = 299792458
d = 75000*c

for w in range(1, 20):
	v = w*w*w*c
	print("Velocity of ship at warp ", w, " is ", v," m/s.")
	years = d/v
	print("At this rate, the Voyager would take ", years, " years to reach home.\n")
