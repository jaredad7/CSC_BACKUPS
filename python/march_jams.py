import pygame
import random
"""
This script will play a shuffled playlist of marches without ceasing.
This script will not play the same march twice in a row.
"""

#initialize things
pygame.init()
pygame.mixer.init()
random.seed()#use sys time

#main
old = -1
rand = random.randint(0, 7)
print("Press 'ctrl c' to end.\r")
while True:
	if not pygame.mixer.music.get_busy() and not rand == old:
		if rand == 0:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/Luftwaffe March.mp3")
		elif rand == 1:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/National Emblem March.mp3")
		elif rand == 2:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/The Liberty Bell March.mp3")
		elif rand == 3:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/US Armed Forces.mp3")
		elif rand == 4:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/El Capitan.mp3")
		elif rand == 5:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/King Cotton March.mp3")
		elif rand == 6:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/Saber and Spurs March.mp3")
		elif rand == 7:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Marches/In Storm and Sunshine.mp3")

		pygame.mixer.music.play(loops = 0)
		old = rand

	rand = random.randint(0, 7)
		
