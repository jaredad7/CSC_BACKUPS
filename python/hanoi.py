#Play the Tower of Hanoi game given a number of discs

def Hanoi(discs, t1, t2, t3):
	if discs > 0:
		Hanoi(discs-1, t1, t3, t2)
		print(str(discs) + " disc to " + t3 + " peg")
		Hanoi(discs-1, t2, t1, t3)

disc = int(28)

Hanoi(disc, "Source", "Spare", "Destination")
