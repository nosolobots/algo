#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#import pdb; pdb.set_trace()
import random
import sort

def init_data(points):
    data = [i for i in range(points)]

    # shuffle data
    random.seed()
    for i in range(len(data)-1,1,-1):
        j = random.randint(0, i)
        temp = data[j]
        data[j] = data[i]
        data[i] = temp    

    return data

if __name__ == "__main__":
    # test_data = (19, 31, -2, 5, 42, 1, 22)
    test_data = init_data(100)

    data = list(test_data)

    print("Merge sort: ")
    print(data)
    sort.merge_sort(data, 0, len(data)-1)
    print(data)