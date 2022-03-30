# -*- coding: utf-8 -*-

import threading
import time
import logging
from enum import Enum

class Algo(Enum):
    BUBBLE = 1
    SELECTION = 2
    INSERTION = 3
    MERGE = 4

def bubble_sort(data, delay=0, ord=-1):
    """Implementacón del algoritmo de ordenación de burbuja (bubble sort).

    Args:
        data: lista de números.
        delay: retardo en segundos (thread sleep) (default=0).
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (to-do).
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
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (to-do).
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
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (to-do).
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

def merge_sort(data, ini, end, delay=0, ord=-1):
    """Implementacón del algoritmo de ordenación de mezcla (merge sort).

    Args:
        data: lista de números.
        ini: index of the first element
        end: index of the last element
        delay: retardo en segundos (thread sleep) (default=0).
        ord: tipo de ordenación (-1=decreciente, 1=creciente) (to-do).
    """
    l = end - ini + 1

    if l==1: return

    m = (int)(ini + l/2) # mid index

    merge_sort(data, ini, m-1, delay, ord)
    merge_sort(data, m, end, delay, ord)

    # do the merging of the two partitions
    merge(data, ini, m, end, delay, ord)

def merge(data, ini, m, end, delay=0, ord=-1):
    #print(ini, m, end)
    if data[m-1] >= data[m]: return # the two partitions are already sorted

    l = ini
    r = m

    temp = []   # temporary list

    # add the smaller of both partitions in each iteration
    while l<m and r<=end:
        if data[l] > data[r]:
            temp.append(data[l])
            l += 1
        else:
            temp.append(data[r])
            r += 1

    # add the remaining (if the remaining belong to right partition, we don't have to)
    while l<m:
        temp.append(data[l])
        l += 1

    # copy temp data
    i = ini
    for e in temp:
        data[i] = e
        i += 1
        time.sleep(delay)

def init(algo, data, delay):
    t = None
    if algo == Algo.BUBBLE:
        t = threading.Thread(target=bubble_sort,args=(data,delay), daemon=False)
    elif algo == Algo.SELECTION:
        t = threading.Thread(target=selection_sort,args=(data,delay), daemon=False)
    elif algo == Algo.INSERTION:
        t = threading.Thread(target=insertion_sort,args=(data,delay), daemon=False)
    elif algo == Algo.MERGE:
        t = threading.Thread(target=merge_sort,args=(data, 0, len(data)-1, delay), daemon=False)
    if t:
        t.start()

    return t


