import threading
import time
import logging
from enum import Enum

class Algo(Enum):
    BUBBLE = 1
    SELECTION = 2
    INSERTION = 3

def bubble_sort(data, delay=0, ord=-1):
    """Implementacón del algoritmo de ordenación de burbuja (bubble sort).

    Args:
        data: lista de números.
        delay: retardo en segundos (thread sleep) (default=0).
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (todo).
    """
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

def selection_sort(data, delay=0, ord=-1):
    """Implementacón del algoritmo de ordenación de selección (selection sort).

    Args:
        data: lista de números.
        delay: retardo en segundos (thread sleep) (default=0).
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (todo).
    """
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

def insertion_sort(data, delay=0, ord=-1):
    """Implementacón del algoritmo de ordenación de inserción (insertion sort).

    Args:
        data: lista de números.
        delay: retardo en segundos (thread sleep) (default=0).
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (todo).
    """
    for i in range(1, len(data)):   # index of the value to be inserted in its right position
        val = data[i]   # value to insert
        p = i-1         # insertion pos
        while(p>=0 and val>data[p]): 
            data[p+1] = data[p]
            p -= 1
            #delay
            time.sleep(delay)
        data[p+1] = val   # insert number

def init(algo, data, delay):
    t = None
    if algo == Algo.BUBBLE:
        t = threading.Thread(target=bubble_sort,args=(data,delay), daemon=False)
    elif algo == Algo.SELECTION:
        t = threading.Thread(target=selection_sort,args=(data,delay), daemon=False)    
    elif algo == Algo.INSERTION:
        t = threading.Thread(target=insertion_sort,args=(data,delay), daemon=False)    
    if t:
        t.start()
    
    return t


