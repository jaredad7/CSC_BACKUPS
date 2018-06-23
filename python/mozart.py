import pygame
import time
import sys
import random

#initialize things
pygame.init()
pygame.mixer.init()
random.seed()
#get input
print("Please select a time duration for your music")
print("1) 15 min")
print("2) 30 min")
print("3) 45 min")
print("4) 60 min")
length = int(input("Please enter 1, 2, 3, or 4: "))
while length != 1 and length != 2 and length != 3 and length != 4:
	print("Invalid input!")
	length = int(input("Please enter 1, 2, 3, or 4: "))

start_time = time.time()
old = -1
rand = random.randint(0, 5)
print("Press 'ctrl c' to end.\r")
if length == 1:
	while time.time() - start_time < 15*60:
		if not pygame.mixer.music.get_busy() and not rand == old:
			print("playing")
			if rand == 0:
				pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Mozart/M1.mp3")
			elif rand == 1:
				pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Mozart/M2.mp3")
			elif rand == 2:
				pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Mozart/M3.mp3")
			elif rand == 3:
				pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Mozart/M4.mp3")
			elif rand == 4:
				pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Mozart/M5.mp3")
			pygame.mixer.music.play(loops = 0)
			old = rand

	rand = random.randint(0, 5)

