import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.*;

public class Sudoku {
  
  public static final int N = 9; // number of rows and columns in sudoku 
  public static final int EMPTY = 0; // EMPTY cell identifier
  public static final int BOX_SIZE = (int) Math.sqrt(N);
  public static final int FilledCellsPercentages = 35; 

  private int[][] gameField; // game field

  Sudoku() {
    gameField = new int[N][N];

    generate_game_field();

    write_to_file();
  }

  Sudoku(int[][] gameField) {
    this.gameField = gameField;

    write_to_file();
  }

  public void generate_game_field() {
    fill_values();
    remove_some_values();
  }

  void remove_some_values() {
    double unfilledCellsPart = (double) (100 - FilledCellsPercentages) / 100;
    int gameFieldCellsNumber = (int) Math.pow(N, 2);
    
    int removableCellsNumber = (int) Math.floor(unfilledCellsPart 
                                              * gameFieldCellsNumber);
    
    int counter = 0;

    while (counter <= removableCellsNumber) {
      int random_row = (int) Math.floor(Math.random() * N);
      int random_column = (int) Math.floor(Math.random() * N);

      if (gameField[random_row][random_column] != EMPTY) {
        gameField[random_row][random_column] = 0;
        counter++;
      }
    }
  }

  void fill_values() {
    fill_diagonal_box_cells();
    fill_remaining_cells(false);
  }

  void fill_diagonal_box_cells() {
    for (int i = 0; i < N; i = i + BOX_SIZE)
      fill_box(i, i);
  }

  void fill_box(int row, int column) {
    int randomNumber;

    for (int i = 0; i < BOX_SIZE; i++) {
      for (int j = 0; j < BOX_SIZE; j++) {

        do {
          randomNumber = (int) Math.floor(Math.random() * N + 1); 
        }
        while (used_in_box(row, column, randomNumber));

        gameField[row + i][column + j] = randomNumber;
      }
    } 
  }

  boolean used_in_box(int starting_row, int starting_column, int number) {
    for (int i = 0; i < BOX_SIZE; i++) 
      for (int j = 0; j < BOX_SIZE; j++)
        if (gameField[i + starting_row][j + starting_column] == number)
          return true;
    
    return false;
  }

  boolean fill_remaining_cells(boolean writeToFile) {  
    int[] location = find_empty_cell(); // array with row and column numbers or one zero if fn could't find empty cell
    
    int row = 0;
    int column = 0;

    if (location.length == 1) {
      if (writeToFile) write_to_file();
      return true;
    }

    if (location.length == 2) {
      row = location[0];
      column = location[1];
    }

    for (int number = 1; number <= N; number++) {
      
      if (isSafe(row, column, number)) {
        gameField[row][column] = number;
      
        if (fill_remaining_cells(writeToFile))
          return true;
        
        gameField[row][column] = EMPTY;
      }
    }

    return false;
  }

  int[] find_empty_cell() {
    for (int row = 0; row < N; row++)
      for (int column = 0; column < N; column++)
        if (gameField[row][column] == EMPTY)
          return new int[] {row, column};
    
    return new int[] {0};
  }

  boolean used_in_row(int row, int number) {
    for (int column = 0; column < N; column++)
      if (gameField[row][column] == number)
        return true;
    
    return false;
  }

  boolean used_in_column(int column, int number) {
    for (int row = 0; row < N; row++)
      if (gameField[row][column] == number)
        return true;
    
    return false;
  }

  boolean isSafe(int row, int column, int number) {
    return !used_in_row(row, number) &&
           !used_in_column(column, number) &&
           !used_in_box(row - row % BOX_SIZE, 
                        column - column % BOX_SIZE,
                        number);
  } 

  void write_to_file() {
    try {
      FileWriter fileWriter = new FileWriter("solutions.txt", true);
      BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
      PrintWriter printWriter = new PrintWriter(bufferedWriter);

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          printWriter.print(gameField[i][j] + " ");
        }
        printWriter.println();
      }
      printWriter.println();
      
      printWriter.close();
    } catch(IOException exception) {
      System.out.println("Something go wrong!");
    }
  }

  void print_game_field() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        System.out.print(gameField[i][j] + " ");
      }
      System.out.println();
    }
    System.out.println();
  }

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