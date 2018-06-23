#You can walk around

room_center = """

__________          __________
|                            |
|			     |
|			     |
|			     |

              ME

|			     |
|                            |
|			     |
|_________          _________|			     

"""

room_up = """

______________________________
|                            |
|			     |
|			     |
|			     |
|			     |
|             ME	     |
|			     |
|			     |
|                            |
|			     |
|_________          _________|			     

"""

room_down = """

__________          __________
|                            |
|			     |
|			     |
|			     |
|			     |
|             ME	     |
|			     |
|			     |
|                            |
|			     |
|____________________________|			     

"""

room_left = """

______________________________
|                            |
|			     |
|			     |
|			     |
|
|             ME
|
|			     |
|                            |
|			     |
|____________________________|			     

"""

room_right = """

______________________________
|                            |
|			     |
|			     |
|			     |
			     |
	      ME	     |
			     |
|			     |
|                            |
|			     |
|____________________________|			     

"""

state = "CENTER"
print(room_center)

while True:
	walk = input("Walk which way? ['up' 'left' 'right' 'down']: ")
	
	if walk == "up" and state != "UP" and state != "RIGHT" and state != "LEFT":
		if state == "CENTER":
			state = "UP"
		else:
			state = "CENTER"		
	elif walk == "down" and state != "DOWN" and state != "LEFT" and state != "RIGHT":
		if state == "CENTER":
			state = "DOWN"
		else:
			state = "CENTER"
	elif walk == "right" and state != "RIGHT" and state != "UP" and state != "DOWN":
		if state == "CENTER":
			state = "RIGHT"
		else:
			state = "CENTER"
	elif walk == "left" and state != "LEFT" and state != "UP" and state != "DOWN":
		if state == "CENTER":
			state = "LEFT"
		else:
			state = "CENTER"
	else:
		print("Uh-oh, we got a badass over here,")
		print("Tryin-a move through walls and shit!!!")

	if state == "CENTER":
		print(room_center)
	elif state == "LEFT":
		print(room_left)
	elif state == "RIGHT":
		print(room_right)
	elif state == "UP":
		print(room_up)
	elif state == "DOWN":
		print(room_down)
	else:
		print("Oh, shit! Nigga really do move through walls!!!\n")


