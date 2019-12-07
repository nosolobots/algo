#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#import pdb; pdb.set_trace()

import sys
import random
import pygame
import sort
import threading
import time
from pygame.locals import *

_POINTS = 100
_POINT_W = 10 
_DELAY = 0.002

_SCR_W = _POINTS * _POINT_W
_SCR_H = _POINTS * _POINT_W

_BGCOL = (255, 255, 255)
_FGCOL = (0, 0, 125)

def init_display():
    scr = pygame.display.set_mode((_SCR_W, _SCR_H))
    scr.fill((255,255,255))
    pygame.display.set_caption("Points")
    pygame.display.flip()

    return scr

def init_data():
    data = [i for i in range(_POINTS)]

    # shuffle data
    random.seed()
    for i in range(len(data)-1,1,-1):
        j = random.randint(0, i)
        temp = data[j]
        data[j] = data[i]
        data[i] = temp    

    return data

def show_data(scr, data):
    scr.fill(_BGCOL)

    x = 0
    for y in data:
        xcoord = x*_POINT_W
        ycoord = y*_POINT_W
        pygame.draw.rect(scr, _FGCOL, (xcoord, ycoord, _POINT_W, _POINT_W), 0)
        x += 1

def main():
    scr = init_display()
    data = init_data()

    sort_thread = None
    while(True):
        for event in pygame.event.get():
            if event.type == QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == K_ESCAPE:   # exit
                    sys.exit()
                elif event.key == K_r:      # restart
                    data = init_data()
                elif event.key == K_b:      # bubble sort
                    print("Bubble sort")                    
                    sort_thread = sort.init(sort.Algo.BUBBLE, data, _DELAY)
                elif event.key == K_s:      # selection sort
                    print("Selection sort")                    
                    sort_thread = sort.init(sort.Algo.SELECTION, data, _DELAY)                    

        show_data(scr, data)
        pygame.display.flip()        
    
if __name__ == "__main__":
    pygame.init()
    main()
