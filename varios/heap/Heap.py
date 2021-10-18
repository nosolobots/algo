import math

class Heap:
    def __init__(self):
        self.data = []

    def empty(self):
        return len(self.data) == 0

    def size(self):
        return len(self.data)

    def insert(self, value):
        '''abstract.'''
        pass

    def heapify(self, arr):
        for n in arr:
            self.insert(n)

    def extract(self):
        '''abstract.'''
        return None

    def swap(self, i, j):
        t = self.data[i]
        self.data[i] = self.data[j]
        self.data[j] = t

class MaxHeap(Heap):
    def insert(self, value):
        self.data.append(value)

        i = len(self.data) - 1
        p = math.floor((i - 1)/2)
        while p >= 0 and self.data[i] > self.data[p]:
            self.swap(i, p)
            i = p
            p = math.floor((i - 1)/2)

    def extract(self):
        if len(self.data) == 0: return None
        if len(self.data) == 1: return self.data.pop()

        root = self.data[0]
        self.data[0] = self.data.pop()  # reemplaza raíz por último

        p = 0
        order = False
        while not order:
            hijo = p
            le = 2*p + 1
            ri = le + 1

            if ri < len(self.data) and le < len(self.data):
                if self.data[ri] > self.data[le]:
                    hijo = ri
                else:
                    hijo = le
            elif le < len(self.data):
                hijo = le

            if self.data[p] < self.data[hijo]:
                self.swap(p, hijo)
                p = hijo
            else:
                order = True
            
        return root


class MinHeap(Heap):
    def insert(self, value):
        self.data.append(value)

        i = len(self.data) - 1
        p = math.floor((i - 1)/2)
        while p >= 0 and self.data[i] < self.data[p]:
            self.swap(i, p)
            i = p
            p = math.floor((i - 1)/2)

    def extract(self):
        if len(self.data) == 0:
            return None
        if len(self.data) == 1:
            return self.data.pop()

        root = self.data[0]
        self.data[0] = self.data.pop()  # reemplaza raíz por último

        p = 0
        order = False
        while not order:
            hijo = p
            le = 2*p + 1
            ri = le + 1

            if ri < len(self.data) and le < len(self.data):
                if self.data[ri] < self.data[le]:
                    hijo = ri
                else:
                    hijo = le
            elif le < len(self.data):
                hijo = le

            if self.data[p] > self.data[hijo]:
                self.swap(p, hijo)
                p = hijo
            else:
                order = True

        return root

if __name__ == '__main__':
    values = [3, 4, 5, 11, 8, 15]
    print("data:", values)
    
    min_heap = MinHeap()
    min_heap.heapify(values)
    
    print("min_heap:", min_heap.data)
    print("inc order-> [", end='')
    while not min_heap.empty():
        print(min_heap.extract(), end=', ')
    print('\b\b]')

    max_heap = MaxHeap()
    max_heap.heapify(values)
    
    print("max_heap:", max_heap.data)
    print("dec order-> [", end='')
    while not max_heap.empty():
        print(max_heap.extract(), end=', ')
    print('\b\b]')
