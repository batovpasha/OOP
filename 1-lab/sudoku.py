import math

N = 9
EMPTY = 0
BOX_SIZE = int(math.sqrt(N))

print(BOX_SIZE)

class Sudoku:
    __gameField = [ [ 0 for x in range(N) ] for x in range(N) ]

    def get_game_field(self):
        return self.__gameField

sudoku = Sudoku()

print(sudoku.get_game_field())

