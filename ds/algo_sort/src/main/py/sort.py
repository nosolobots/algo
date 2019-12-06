import threading
import time
import logging
from enum import Enum

class Algo(Enum):
    BUBBLE = 1

def bubble_sort(data, delay):
    print("bubble_sort: init")

    swap = True
    
    n = len(data) - 1
    while(swap):
        swap = False
        for i in range(n):
            time.sleep(delay)

            if data[i] < data[i+1]:
                temp = data[i+1]
                data[i+1] = data[i]
                data[i] = temp
                swap = True
        n -= 1

    print("bubble_sort: end")

def init(algo, data, delay):
    t = None
    if algo == Algo.BUBBLE:
        t = threading.Thread(target=bubble_sort,args=(data,delay), daemon=True)
    
    if t:
        t.start()


