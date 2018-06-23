import pygame
import time
import sys

#run an wav file.
#alarm.py to be called from alarm.sh
#initialize things
pygame.init()
pygame.mixer.init()
pygame.mixer.music.load("/home/jared/CSC_CYEN/python/pyMusic/confusionmusic.wav")

pygame.mixer.music.play(loops = -1)
x = input("Press ENTER to end")

