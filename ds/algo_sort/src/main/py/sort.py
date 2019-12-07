import threading
import time
import logging
from enum import Enum

class Algo(Enum):
    BUBBLE = 1
    SELECTION = 2

def bubble_sort(data, delay):
    n = len(data) - 1

    swap = True
    while(swap):
        swap = False
        for i in range(n):
            #delay
            time.sleep(delay)

            if data[i] < data[i+1]:
                temp = data[i+1]
                data[i+1] = data[i]
                data[i] = temp
                swap = True
        n -= 1

def selection_sort(data, delay):
    n = len(data)-1     # unsorted partition index
    while(n>0):
        index = 0       # index of current min value
        for i in range(1, n+1):
            if data[i]<data[index]: index = i
            #delay
            time.sleep(delay)

        if index != n:
            # swap
            temp = data[n]
            data[n] = data[index]
            data[index] = temp

        n -= 1

def init(algo, data, delay):
    t = None
    if algo == Algo.BUBBLE:
        t = threading.Thread(target=bubble_sort,args=(data,delay), daemon=False)
    elif algo == Algo.SELECTION:
        t = threading.Thread(target=selection_sort,args=(data,delay), daemon=False)    

    if t:
        t.start()
    
    return t


