"""
    Shortest path

    input:
        4
        0010
        0010
        1000
        0010

        first line: number of rows/cols
        0: empty cell
        1: wall cell
"""

import heapq

def process_input(n):
    board = []
    while n>0:
        board.append([int(cell) for cell in input()])
        n -= 1
    return board

def sp_greedy(board, src, dst):
    """
    Find path using a greedy algorithm.

    Args:
        board: the maze
        src: start cell tuple
        dst: destination cell tuple

    Returns:
        path: list of path cells
    """
    height = len(board)
    width = len(board[0])
    path = []
    closed = []
    dirs = [(0,-1), (1,0), (0,1), (-1,0)]

    cells = [(0, src)]
    heapq.heapify(cells)
    reached = False
    while len(cells) > 0:
        dist, cell = heapq.heappop(cells)
        if cell == dst:
            print("Reached!")
            reached = True
            break

        closed.append(cell)
        for d in dirs:
            new_cell = (cell[0] + d[0], cell[1] + d[1])

            if new_cell[0]<0 or new_cell[1]<0 or \
                    new_cell[0]==width or new_cell[1]==height:
                continue

            if board[new_cell[0]][new_cell[1]] != 0:
                continue

            if new_cell in closed:
                continue

            heapq.heappush(cells, (dist+1, new_cell))
            path.append(new_cell)
    return reached, path

def sp_djkstra(board, src, dst):
    """
    Find path using a djkstra algorithm.

    Args:
        board: the maze
        src: start cell tuple
        dst: destination cell tuple

    Returns:
        path: list of path cells
    """
    height = len(board)
    width = len(board[0])
    dirs = [(0,-1), (1,0), (0,1), (-1,0)]

    distances = {(i,j):float('inf') for i in range(height) for j in range(width)}

    path = []
    open_list = [(0, src)]
    distances[(0,0)] = 0

    reached = False

    while len(open_list) > 0:
        dist, node = heapq.heappop(open_list)

        if dist > distances[node]:
            continue

        if node == dst:
            print("Reached!")
            reached = True
            break

        for d in dirs:
            new_node = (node[0] + d[0], node[1] + d[1])

            if new_node[0]<0 or new_node[1]<0 or \
                    new_node[0]==width or new_node[1]==height:
                continue

            if board[new_node[0]][new_node[1]] != 0:
                continue

            new_dist = dist + 1
            if new_dist < distances[new_node]:
                distances[new_node] = new_dist
                heapq.heappush(open_list, (new_dist, new_node))
                path.append(new_node)

    return reached, path

def sp_djkstra_path(board, src, dst):
    """
    Find shortest path using a djkstra algorithm.

    Args:
        board: the maze
        src: start cell tuple
        dst: destination cell tuple

    Returns:
        path: list of path cells
    """
    class Node():
        def __init__(self, coords, dist, parent):
            self._c = coords
            self._d = dist
            self._p = parent

        @property
        def coords(self): return self._c

        @property
        def dist(self): return self._d
        @dist.setter
        def dist(self, d): self._d = d

        @property
        def parent(self): return self._p

        def __eq__(self, other): return self.coords == other.coords

        @staticmethod
        def search_min(node_list):
            min_index = 0
            min_node = node_list[min_index]
            for index, node in enumerate(node_list):
                if node.dist < min_node.dist:
                    min_node = node
                    min_index = index
            return min_index

        @staticmethod
        def create_path(src_node, dst_node):
            path = []
            node = dst_node.parent
            while node != src_node:
                path.append(node.coords)
                node = node.parent
            return path[::-1]

    height = len(board)
    width = len(board[0])
    close_list = []
    open_list = []
    dirs = [(0,-1), (1,0), (0,1), (-1,0)]

    start_node = Node(src, 0, None)
    dest_node = Node(dst, float('inf'), None)

    open_list.append(start_node)

    reached = False
    path = []

    while len(open_list) > 0:
        node = open_list.pop(Node.search_min(open_list))
        close_list.append(node)

        if node == dest_node:
            print("Reached!")
            reached = True
            path = Node.create_path(start_node, node)
            break

        for d in dirs:
            new_node_coords = (node.coords[0] + d[0], node.coords[1] + d[1])
            new_node = Node(new_node_coords, node.dist + 1, node)

            if new_node.coords[0]<0 or new_node.coords[1]<0 or \
                    new_node.coords[0]==width or new_node.coords[1]==height:
                continue

            if board[new_node.coords[0]][new_node.coords[1]] != 0:
                continue

            if new_node in close_list:
                continue

            if new_node in open_list:
                open_node = open_list[open_list.index(new_node)]
                if new_node.dist < open_node.dist:
                    open_node.dist = new_node.dist
                    open_node.parent = new_node.parent
            else:
                open_list.append(new_node)

    return reached, path

def show_map(board, path, src, dst, src_ch='◈', dst_ch='◉', \
        wall_ch='▧', free_ch='◦', path_ch='▴'):
    height = len(board)
    width = len(board[0])

    for i in range(height):
        for j in range(width):
            if (i,j) == src:
                print("\033[38;5;9m\033[48;5;2m" + src_ch, end='')
            elif (i,j) == dst:
                print("\033[38;5;13m\033[48;5;2m" + dst_ch, end='')
            elif (i,j) in path:
                print("\033[38;5;11m\033[48;5;2m" + path_ch, end='')
            elif board[i][j] == 1:
                print("\033[38;5;15m\033[48;5;8m" + wall_ch, end='')
            else:
                print("\033[38;5;3m\033[48;5;2m" + free_ch, end='')
        print('\033[38;5;15m\033[48;5;0m ')

if __name__ == '__main__':
    n = int(input())
    board = process_input(n)
    src = (0,0)
    dst = (7,7)
    reached, path = sp_djkstra_path(board, src, dst)
    print(path)
    print(reached)
    show_map(board, path, src, dst)
