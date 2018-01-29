#!/usr/bin/python

import serial, pygame, sys
from pygame.locals import *

pygame.init()

s = serial.Serial("/dev/ttyACM0")

DISPLAYSURF = pygame.display.set_mode((400, 300))
pygame.display.set_caption('Color Changer')

while(True):
  l = s.readline()
  x = l.rstrip().split(",")
  rgb = [ int(val) for val in x]

  print rgb

  pygame.Color(rgb[0], rgb[1], rgb[2])
  
  for event in pygame.event.get():
    if event.type == QUIT:
      pygame.quit()
      sys.exit()
  pygame.display.update()






