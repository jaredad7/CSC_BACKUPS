#tests if I can send commands to a terminal via python and os.system()

import os

while True:
	grab = input("Input Command: ")
	os.system(grab)

