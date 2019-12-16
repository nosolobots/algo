#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#import pdb; pdb.set_trace()

import sort

if __name__ == "__main__":
    test_data = (19, 31, -2, 5, 42, 1, 22)

    data = list(test_data)

    print("Merge sort: ")
    print(data)
    sort.merge_sort(data)
    print(data)