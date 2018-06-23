import pygame
import random
"""
This script will play a shuffled playlist of sinatra tunes without ceasing.
This script will not play the same march twice in a row.
"""

#initialize things
pygame.init()
pygame.mixer.init()
random.seed()#use sys time

#main
old = -1
rand = random.randint(0, 5)
print("Press 'ctrl c' to end.\r")
while True:
	if not pygame.mixer.music.get_busy() and not rand == old:
		if rand == 0:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Sinatra/Blue Moon.mp3")
		elif rand == 1:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Sinatra/Come Fly with Me.mp3")
		elif rand == 2:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Sinatra/Fly Me to the Moon.mp3")
		elif rand == 3:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Sinatra/My Way.mp3")
		elif rand == 4:
			pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/Sinatra/New York, New York.mp3")

		pygame.mixer.music.play(loops = 0)
		old = rand

	rand = random.randint(0, 5)
		
