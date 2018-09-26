import math
import random

N = 9 # number of rows and columns in sudoku
EMPTY = 0 # empty cell identifier
BOX_SIZE = int(math.sqrt(N)) # box size is 3 x 3
FILLED_CELLS_PERCENTAGES = 35 # percents of filled cells


class Sudoku:
    __gameField = [ [] for x in range(N) ] # game field 9 x 9 size with "empty" cells by default

    def __init__(self, *args):
        pass
