#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#import pdb; pdb.set_trace()

import sys
import random
import pygame
import threading
import time
from pygame.locals import *
import numpy as np

class COLORS():
    _BLACK = (0, 0, 0)
    _GRAY = (127, 127, 127)
    _WHITE = (255, 255, 255)
    _RED = (255, 0, 0)
    _GREEN = (0, 255, 0)
    _BLUE = (0, 0, 255)
    _YELLOW = (255, 255, 0)
    _CYAN = (0, 255, 255)
    _MAGENTA = (255, 0, 255)
    _L_GREEN = (150, 255, 150)
    _L_BROWN = (250, 100, 90)

class CellGraph():
    _COLORS = (COLORS._GREEN, COLORS._YELLOW, COLORS._RED, COLORS._BLUE, COLORS._L_GREEN, COLORS._L_BROWN)

    def __init__(self, x, y, w, node, scr):
        self._x = x
        self._y = y
        self._w = w
        self._n = node
        self._scr = scr

    def paint(self):
        pygame.draw.rect(self._scr, CellGraph._COLORS[self._n.type],
            pygame.Rect(self._x, self._y, self._w, self._w), 0)

class CellNode():
    _FREE = 0
    _START = 1
    _END = 2
    _WATER = 3
    _CHECK = 4
    _PATH = 5

    def __init__(self, row, col, type=0):
        self._r = row
        self._c = col
        #self._t = random.randint(0,3)
        self._t = 0
        self._g = None

        # algorithm
        self._alg_parent = None
        self._alg_score = 0
        # dijkstra & A* cost from start
        self._alg_g = 0
        # A* heuristic
        self._alg_h = 0

    @property
    def row(self): return self._r

    @property
    def col(self): return self._c

    @property
    def type(self): return self._t

    @type.setter
    def type(self, t): self._t = t

    @property
    def path_parent(self): return self._alg_parent

    @path_parent.setter
    def path_parent(self, node): self._alg_parent = node

    @property
    def score(self): return self._alg_score

    @property
    def cost(self): return self._alg_g

    @cost.setter
    def cost(self, g):
        self._alg_g = g
        self._alg_score = g + self._alg_h

    @property
    def heuristic(self): return self._alg_h

    @heuristic.setter
    def heuristic(self, h): self._alg_h = h

    def set_graphic(self, scr, width):
        self._g = CellGraph(self._c*width, self._r*width, width, self, scr)

    def paint(self):
        if self._g:
            self._g.paint()

def path_finding(node_list, path, start, end, diag=False, cost=10, dcost=14,
                        paint_search=False, alg='dijkstra', delay=.0):
    rows = len(node_list)
    cols = len(node_list[0])

    # lista de nodos pendientes
    opened_nodes = {start: node_list[start[0]][start[1]]}

    # lista de nodos procesados
    closed_nodes = dict()

    # nodo actual
    cur_node = None

    # mientras haya nodos pendientes
    while len(opened_nodes):
        # obtenemos el nodo con menor coste total (score)
        cur_node = find_node(opened_nodes)

        # si es el nodo final, terminamos
        if cur_node == node_list[end[0]][end[1]]: break

        # lo eliminamos de la lista de pendientes
        pos = (cur_node.row, cur_node.col)
        del opened_nodes[pos]

        # lo añadimos a la lista de nodos procesados
        closed_nodes[pos] = cur_node
        if paint_search and cur_node.type != CellNode._START:
            cur_node.type = CellNode._CHECK

        # extraemos sus nodos vecinos
        neighbours = []

        # up
        if pos[0]:
            neighbours.append(node_list[pos[0]-1][pos[1]])
        # left col
        if pos[1]:
            neighbours.append(node_list[pos[0]][pos[1]-1])
            if diag and pos[0]:
                neighbours.append(node_list[pos[0]-1][pos[1]-1])
            if diag and pos[0] < rows-1:
                neighbours.append(node_list[pos[0]+1][pos[1]-1])
        # down
        if pos[0] < rows-1:
            neighbours.append(node_list[pos[0]+1][pos[1]])
        # right col
        if pos[1] < cols-1:
            neighbours.append(node_list[pos[0]][pos[1]+1])
            if diag and pos[0]:
                neighbours.append(node_list[pos[0]-1][pos[1]+1])
            if diag and pos[0] < rows-1:
                neighbours.append(node_list[pos[0]+1][pos[1]+1])

        # analizamos los vecinos
        while len(neighbours):
            if delay: time.sleep(delay)

            neighbour = neighbours.pop()
            neighbour_pos = (neighbour.row, neighbour.col)

            # si es transitable y no se procesó aún
            if neighbour.type != CellNode._WATER and neighbour_pos not in closed_nodes:
                # si algo es A* calculamos su heurística (si no está calculada ya)
                if alg == 'A*' and not neighbour.heuristic:
                    neighbour.heuristic = abs(end[0] - neighbour_pos[0]) +  abs(end[1] - neighbour_pos[1])

                # calculamos su coste desde el nodo actual
                ncost = cur_node.cost
                if diag and neighbour_pos[0] != pos[0] and neighbour_pos[1] != pos[1]:
                    ncost += dcost
                else:
                    ncost += cost

                # si ya está en la lista abierta y el coste desde la celda actual es menor...
                if neighbour_pos in opened_nodes:
                    if ncost < neighbour.cost:
                        # cambiamos el coste del vecino y su padre
                        neighbour.cost = ncost
                        neighbour.path_parent = cur_node
                else:
                    # establecemos el coste del vecino y su padre
                    neighbour.cost = ncost
                    neighbour.path_parent = cur_node
                    # lo añadimos a la lista abierta
                    opened_nodes[neighbour_pos] = neighbour

    # Construimos la ruta
    if cur_node == node_list[end[0]][end[1]]:
        prev_node = cur_node.path_parent
        while prev_node != node_list[start[0]][start[1]]:
            path.append(prev_node)
            prev_node.type = CellNode._PATH
            prev_node = prev_node.path_parent

def find_node(node_dict):
    # busca el nodo con un coste inferior
    node = list(node_dict.values())[0]
    for k, n in node_dict.items():
        if n.score < node.score:
            node = n
    return node

class Display():
    def __init__(self, rows, cols, cell_w, title="Path Finding", grid=True):
        self._rows = rows
        self._cols = cols
        self._grid = grid
        self._cell_w = cell_w
        self._scr_w = cols * cell_w
        self._scr_h = rows * cell_w
        self._scr = pygame.display.set_mode((self._scr_w, self._scr_h))
        #self._scr.fill(COLORS.GREEN)
        pygame.display.set_caption(title)

    @property
    def scr(self): return self._scr

    def update(self):
        if self._grid:
            self.paint_grid()
        pygame.display.flip()

    def paint_grid(self):
        pygame.draw.rect(self._scr, COLORS._GRAY, pygame.Rect(0, 0, self._scr_w-1, self._scr_h-1), 2)
        for x in range(0, self._scr_h, self._cell_w):
            for y in range(0, self._scr_w, self._cell_w):
                pygame.draw.rect(self._scr, COLORS._GRAY,
                    pygame.Rect(x, y, self._cell_w, self._cell_w), 1)

def init_data(rows, cols, width=None, scr=None):
    data = [[CellNode(r, c) for c in range(cols)] for r in range(rows)]

    # Añadimos el gráfico de la celda al nodo
    if scr and width:
        for row in data:
            for node in row:
                node.set_graphic(scr, width)

    return data

def show_data(data):
    for row in data:
        for node in row:
            node.paint()

def main(rows, cols, width):
    pygame.init()

    # Creamos el display
    display = Display(rows, cols, width)

    # Creamos los nodos con sus gráficos
    node_list = init_data(rows, cols, width, display.scr)

    # init start and end nodes
    type = CellNode._FREE
    start_cell = (0,0)
    end_cell = (rows-1, cols-1)
    node_list[start_cell[0]][start_cell[1]].type = CellNode._START
    node_list[end_cell[0]][end_cell[1]].type = CellNode._END

    # diagonal paths
    diagonal = False

    # algo
    alg_list = ('dijkstra', 'A*')
    alg = 0

    while(True):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:    # exit
                    sys.exit()
                elif event.key == pygame.K_d:       # Diagonal paths
                    diagonal = not diagonal
                    print(f'> diagonal: {diagonal}')
                elif event.key == pygame.K_a:       # Algorithm selection
                    alg ^= 1
                    print(f'> algoritm: {alg_list[alg]}')
                elif event.key == pygame.K_s:       # START cell type
                    print(f'> cell type: START')
                    type = CellNode._START
                elif event.key == pygame.K_e:       # END cell type
                    type = CellNode._END
                    print(f'> cell type: END')
                elif event.key == pygame.K_f:       # FREE cell type
                    type = CellNode._FREE
                    print(f'> cell type: FREE')
                elif event.key == pygame.K_w:       # WATER cell type
                    type = CellNode._WATER
                    print(f'> cell type: WATER')
                elif event.key == pygame.K_c:       # Clear Path
                    for row in node_list:
                        for node in row:
                            if node.type in (CellNode._CHECK, CellNode._PATH):
                                node.type = CellNode._FREE
                elif event.key == pygame.K_p:       # Find Path
                    print(f'> Finding shortest path...', end=' ')
                    path = []
                    path_finding(node_list, path, start_cell, end_cell, diag=diagonal, alg=alg_list[alg])
                    if len(path):
                        print(f'> {len(path)} steps')
                    else:
                        print('> No path to destinty')
                elif event.key == pygame.K_t:       # Show path search (threaded)
                    print(f'> Finding shortest path...', end=' ')
                    path = []
                    t = threading.Thread(target=path_finding, args=(node_list, path, start_cell,
                                 end_cell, diagonal, 10, 14, True, alg_list[alg], .01), daemon=False)
                    t.start()

            elif event.type == pygame.MOUSEBUTTONUP and event.button==1:
                # change cell type
                r = event.pos[1]//width
                c = event.pos[0]//width
                node_list[r][c].type = type

                if type == CellNode._START:
                    # change start cell
                    node_list[start_cell[0]][start_cell[1]].type = CellNode._FREE
                    start_cell = (r, c)
                    node_list[start_cell[0]][start_cell[1]].type = CellNode._START

                elif type == CellNode._END:
                    # change end cell
                    node_list[end_cell[0]][end_cell[1]].type = CellNode._FREE
                    end_cell = (r, c)
                    node_list[end_cell[0]][end_cell[1]].type = CellNode._END

        # show cell nodes
        show_data(node_list)

        # update view
        display.update()

def show_usage():
    lines = [
        "#"*58,
        f"{'P A T H    F I N D I N G':^58}",
        "#"*58,
        "",
        f" uso: python3 {sys.argv[0]} [rows cols width]",
        "",
        " KEYS:",
        " =====",
        "",
        " - Cell Type:",
        "   [S]: start cell",
        "   [E]: end cell",
        "   [F]: free cell",
        "   [W]: water cell",
        "   [E]: end cell",
        "",
        " - Algorithm selection:",
        "   [A]: switch Dijkstra|A#",
        "",
        " - Find path:",
        "   [P]: show path",
        "   [T]: show path search (threaded)",
        "   [D]: switch diagonal search",
        "   [C]: clear path",
        "",
        " [ESC]: exit",
        "",
        "#"*58 ]

    print()
    for s in lines: print_usage_line(s)
    print("\nOUTPUT:\n")

def print_usage_line(s):
    print(f"#{s:58}#")


if __name__ == "__main__":
    _DEFAULT_ROWS = 10
    _DEFAULT_COLS = 10
    _DEFAULT_WIDTH = 50

    rows = _DEFAULT_ROWS
    cols = _DEFAULT_COLS
    width = _DEFAULT_WIDTH

    show_usage()

    if len(sys.argv) == 4:
        rows = int(sys.argv[1])
        cols = int(sys.argv[2])
        width = int(sys.argv[3])

    main(rows, cols, width)
