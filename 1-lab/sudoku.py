import math
import random

N = 9 # number of rows and columns in sudoku
EMPTY = 0 # empty cell identifier
BOX_SIZE = int(math.sqrt(N)) # box size is 3 x 3
FILLED_CELLS_PERCENTAGES = 35 # percents of filled cells


class Sudoku:
    __gameField = [ [] for x in range(N) ] # game field 9 x 9 size with "empty" cells by default

    def __init__(self, *args):
        if not args:
            self.genarate_game_field()

            #write_to_file()
        
        if len(args) == 1:
            self.__gameField = args

            #write_to_file()
    
    def genarate_game_field(self):
        self.fill_values()
        #remove_some_values()
    
    def fill_values(self):
        self.fill_diagonal_box_cells()
        self.fill_remaining_cells()

    def fill_diagonal_box_cells(self):
        for i in range(0, N - 1, BOX_SIZE):
            self.fill_box(i, i)
    
    def fill_box(self, row, column):
        randomNumber = random.randint(1, N)

        for i in range(BOX_SIZE):
            for j in range(BOX_SIZE):

                while self.used_in_box(row, column, randomNumber):
                    randomNumber = random.randint(1, N)

                self.__gameField[row + i][column + j] = randomNumber

    def used_in_box(self, starting_row, starting_column, number):
        for i in range(BOX_SIZE):
            for j in range(BOX_SIZE):
                if self.__gameField[i + starting_row][j + starting_column] == number:
                    return True
        
        return False

    def fill_remaining_cells(self, writeToFile):
        location = self.find_empty_cell() # array with row and column numbers or one zero if fn could't find empty cell
        
        row, column = 0, 0

        if len(location) == 1: # if find_empty_cell return one zero than we complete fill the cells
            #if writeToFile: write_to_file()
            return True
        
        if len(location) == 2:
            row = location[0]
            column =location[1]

        for number in range(1, N):
            if self.is_safe(row, column, number):
                self.__gameField[row][column] = number

                if self.fill_remaining_cells(writeToFile):
                    return True

                self.__gameField[row][column] = EMPTY 
        return False

    def find_empty_cell(self):
        row, column = 0, 0
        
        for row in range(N):
            for column in range(N): 
                if self.__gameField[row][column] == EMPTY:
                    return [row, column]
        return [0]
    
    def used_in_row(self, row, number):
        for column in range(N):
            if self.__gameField[row][column] == number:
                return True
        return False

    def used_in_column(self, column, number):
        for row in range(N):
            if self.__gameField[row][column] == number:
                return True
        return False

    def is_safe(self, row, column, number):
        return not self.used_in_row(row, number) and not self.used_in_column(column, number) and not self.used_in_box(row - row % BOX_SIZE, column - column % BOX_SIZE, number)


sudoku = Sudoku()
