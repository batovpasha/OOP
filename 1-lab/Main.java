import game.Sudoku;

public class Main {

  public static void main(String[] args) {
    Sudoku first_sudoku = new Sudoku();
    System.out.println("First sudoku: ");
    first_sudoku.print_game_field();
    first_sudoku.fill_remaining_cells(true);
    first_sudoku.print_game_field();

    int[][] gameField = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                          {5, 2, 0, 0, 0, 0, 0, 0, 0},
                          {0, 8, 7, 0, 0, 0, 0, 3, 1},
                          {0, 0, 3, 0, 1, 0, 0, 8, 0},
                          {9, 0, 0, 8, 6, 3, 0, 0, 5},
                          {0, 5, 0, 0, 9, 0, 6, 0, 0},
                          {1, 3, 0, 0, 0, 0, 2, 5, 0},
                          {0, 0, 0, 0, 0, 0, 0, 7, 4},
                          {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    
    Sudoku second_sudoku = new Sudoku(gameField);
    System.out.println("Second sudoku: ");
    second_sudoku.print_game_field();
    second_sudoku.fill_remaining_cells(true);
    second_sudoku.print_game_field();
  }
  
}